#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    int A, B, C;
    int K;
    int maior = 0;
    int soma = 0;
    cin >> A >> B >> C;
    cin >> K;
    for (int i = 0; i < K; i++)
    {
        if (A >= B && A >= C)
        {
            A *= 2;
            maior = A;
            soma = B + C;
        }
        else if (B >= A && B >= C)
        {
            B *= 2;
            maior = B;
            soma = A + C;
        }
        else
        {
            C *= 2;
            maior = C;
            soma = A + B;
        }
    }
    cout << maior + soma << endl;
    return 0;
}