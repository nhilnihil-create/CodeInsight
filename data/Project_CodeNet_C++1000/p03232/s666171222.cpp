#include <bits/stdc++.h>
#define int long long
using namespace std;

const int NMAX = 100005;
const int MOD = 1000000007;

int n;
int A[NMAX], B[NMAX];
int inv[NMAX];
int sum[NMAX];

int lgput(int b, int e)
{
    int rez = 1, p = b;
    for (int i = 0; (1 << i) <= e; i++)
    {
        if (e & (1 << i))
        {
            rez = (rez * p) % MOD;
        }
        p = (p * p) % MOD;
    }
    return rez;
}

void faInverse()
{
    for (int i = 1; i <= n; i++)
        inv[i] = lgput(i, MOD - 2);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> A[i];

    faInverse();

    int fact = 1;
    for (int i = 2; i <= n; i++)
        fact = fact * i % MOD;

    for (int i = 1; i <= n; i++)
        sum[i] = (sum[i - 1] + inv[i]) % MOD;

    int rez = 0;
    for (int i = 1; i <= n; i++)
    {
        int b = sum[i] + sum[n - i + 1] - inv[1];
        if (b < 0)
            b += MOD;

        rez = (rez + A[i] * b) % MOD;
    }

    cout << rez * fact % MOD;

    return 0;
}
