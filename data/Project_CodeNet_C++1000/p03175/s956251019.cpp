/*Largest Independent Set Problem

Definindo que dp[atual][0] é o máximo do vértice PRETO atual e
que dp[atual][1] é o máximo do vértice BRANCO atual (como exercício).

Percorrer os vértices recursivamente até a raiz e ir calculando
o máximo permitido no PRETO e BRANCO. O resultado final será
a soma do máximo deles.

Restrições:

PRETO: todos os seus filhos (ou vértices ligados) precisam ser BRANCOS! (evento dependente)
BRANCO: a cor de qualquer um dos seus filhos (vértices) NÃO IMPORTA! (evento independente)

*Eventos Dependentes: multiplicação
*Eventos Independentes: soma e multiplicação
*/

#include <bits/stdc++.h>

#define MAX 100003
#define MODULO 1000000007

using namespace std;

vector<int> grafo[MAX];
long long dp[MAX][2]; //valores das colunas -> 0 - PRETO e 1 - BRANCO 
long N;

//Semelhante ao conceito de DFS: marcar os visitados na matriz e percorrer recursivamente
void LIS(int vAtual, int vPosterior){

    dp[vAtual][0] = dp[vAtual][1] = 1; //Visitado

    //Percorrendo o grafo
    for(int i = 0; i < grafo[vAtual].size(); i++){
        int elemento = grafo[vAtual][i];
        
        if(elemento != vPosterior){
            //DFS
            LIS(elemento, vAtual);

            //PRETO
            dp[vAtual][0] = dp[vAtual][0] * dp[elemento][1] % MODULO;

            //BRANCO
            dp[vAtual][1] = dp[vAtual][1] * ((dp[elemento][0] + dp[elemento][1]) % MODULO) % MODULO;
        }
    }
}

int main(){

    cin >> N;

    for(long i = 1; i < N; i++){
        long valor1, valor2;
        cin >> valor1 >> valor2;

        grafo[valor1].push_back(valor2);
        grafo[valor2].push_back(valor1);
    }

    //Vértice de Início = 1
    LIS(1, 0);

    //Os resultados são armazenados nas primeiras posições do grafo (recursão)
    cout << (dp[1][0] + dp[1][1]) % MODULO << endl;
    
    return 0;
}