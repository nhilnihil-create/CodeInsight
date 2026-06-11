#include <iostream>
#include <fstream>
using namespace std;
long long n, S[405], F[405][405], a[405];
int main()
{
    //freopen("SLIMES.INP", "r", stdin);
    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++) F[i][j] = 1e18;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        S[i] = S[i - 1] + a[i];
        F[i][i] = 0;
    }

    for (int cnt = 1; cnt <= n - 1 ; cnt++)
        for (int i = 1; i <= n - cnt; i++)
        {
            int j = i + cnt;
            for (int mid = i; mid < j; mid++)
                F[i][j] = min(F[i][j], F[i][mid] + F[mid + 1][j]);
            F[i][j] += S[j] - S[i - 1];

        }

    cout <<F[1][n];
    return 0;
}
