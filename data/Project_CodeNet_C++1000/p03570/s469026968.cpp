#include <bits/stdc++.h>

using namespace std;

int Ma[67500000], m;

int main()
{
    string s;
    cin >> s;
    long long n=s.length(), a;
    long long H[n+1], D[n+1];
    for (int i = 0; i < 67500000; i++)
    {
        Ma[i] = 2000000;
    }
    H[0] = 0;
    D[0] = 0;
    Ma[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        D[i] = 2000000000;
        a = s[i-1] - 'a';
        H[i] = (H[i-1] ^ (1 << a));
        for (int y = 0; y < 26; y++)
        {
            int b = (1 << y);
            a = Ma[(b ^ H[i])];
            if (a != 2000000)
            {
                D[i] = min(D[i], a+1);
            }
        }
        a = Ma[H[i]];
        if (a != -1)
        {
            D[i] = min(D[i], a+1);
        }
        m = D[i];
        Ma[H[i]] = min(m, Ma[H[i]]);
    }
    cout << D[n];
    return 0;
}
