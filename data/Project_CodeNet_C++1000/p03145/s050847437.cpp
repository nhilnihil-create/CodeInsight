#include <iostream>

using namespace std;

// Retorna o indice do maior lado
int max(int lados[]) {
    int idx_maior = 0, maior = lados[0];
    
    for(int i = 1; i < 3; i++) {

        if(lados[i] > maior) {
            maior = lados[i];
            idx_maior = i;
        }
    }

    return idx_maior;

}

int main() {
    int lados[3];
    int b, h;
    
    for(int i = 0; i < 3; i++) {
        cin >> lados[i];
    }

    int maior = max(lados);

    b = lados[(maior + 1) % 3];
    h = lados[(maior + 2) % 3];

    cout << (b * h) / 2 << endl;

    return 0;
}