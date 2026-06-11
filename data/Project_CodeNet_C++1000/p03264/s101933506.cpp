#include <iostream>

using namespace std;

void solve(int K)
{
    // Há K/2 números pares entre 1 e K
    // Há (K + 1)/2 números ímpares entre 1 e K
    int even = K / 2, odd = (K + 1)/2;

    // Cada par escolhe um par e um ímpar, logo a resposta é o produto dos totais de ambos tipos
    cout << even * odd << endl;
}

int main()
{
    ios::sync_with_stdio(false);

    int K;
    cin >> K;

    solve(K);

    return 0;
}
