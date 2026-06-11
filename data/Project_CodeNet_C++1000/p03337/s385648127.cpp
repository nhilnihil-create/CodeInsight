#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int x, y;
    cin >> x >> y;
    int maior, soma, subt, mult;
    soma = x + y;
    subt = x - y;
    mult = x * y;
    maior = subt;
    if (soma > maior)
    {
        maior = soma;
    }
    if (mult > maior)
    {
        maior = mult;
    }
    cout << maior << endl;
    return 0;
}