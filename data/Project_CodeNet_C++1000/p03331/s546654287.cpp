#include <iostream>

using namespace std;

int somaDigito (int n) {
    int soma = 0;
    while (n != 0) {
        soma += n % 10;
        n /= 10;
    }
    return soma;
}

int main (void) {
    
    int N;

    cin >> N;

    if (N % 2 == 0 && N % 5 == 0) {
        N /= 2;
        cout << (2 * somaDigito(N)) << endl;
    }
    else {
        cout << somaDigito(N) << endl;
    }

    return 0;
}