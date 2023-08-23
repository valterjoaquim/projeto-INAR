// Valter Josquim.. fiz com colega Elton da silva

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura de um nó da árvore
struct No {
    int dado;
    struct No* esquerda;
    struct No* direita;
};

// Função para criar um novo nó
struct No* criarNo(int dado) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->dado = dado;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

// Definição da estrutura da pilha
struct Pilha {
    int caminho[20]; // Supondo que a árvore tem no máximo 20 nós
    int topo;
};

// Função para criar uma nova pilha
struct Pilha* criarPilha() {
    struct Pilha* novaPilha = (struct Pilha*)malloc(sizeof(struct Pilha));
    novaPilha->topo = -1;
    return novaPilha;
}

// Função para empilhar um valor na pilha
void empilhar(struct Pilha* pilha, int valor) {
    pilha->topo++;
    pilha->caminho[pilha->topo] = valor;
}

// Função para desempilhar um valor da pilha
void desempilhar(struct Pilha* pilha) {
    if (pilha->topo >= 0) {
        pilha->topo--;
    }
}

// Função para imprimir o conteúdo da pilha (caminho)
void imprimirPilha(struct Pilha* pilha) {
    for (int i = 0; i <= pilha->topo; i++) {
        printf("%d ", pilha->caminho[i]);
    }
    printf("\n");
}

// Função para percorrer e imprimir os caminhos de forma ordenada
void imprimirCaminhosOrdenados(struct No* no, struct Pilha* pilha) {
    if (no == NULL) {
        return;
    }

    empilhar(pilha, no->dado);

    if (no->esquerda == NULL && no->direita == NULL) {
        imprimirPilha(pilha);
    } else {
        imprimirCaminhosOrdenados(no->esquerda, pilha);
        imprimirCaminhosOrdenados(no->direita, pilha);
    }

    desempilhar(pilha);
}

int main() {
    // Construindo a árvore com 20 nós
    struct No* raiz = criarNo(1);
    raiz->esquerda = criarNo(2);
    raiz->direita = criarNo(3);
    // Construa o restante da árvore conforme desejado

    struct Pilha* pilha = criarPilha();

    printf("Caminhos de todos os nós (impressão ordenada):\n");
    imprimirCaminhosOrdenados(raiz, pilha);

    return 0;
}
