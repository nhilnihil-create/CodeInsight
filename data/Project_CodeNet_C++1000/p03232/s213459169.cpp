#include <iostream>
#include <cstdio>
using namespace std;

const int N = 100005, MOD = 1E9 + 7;

int n, a[N];
long long ans = 0, fct = 1, inv[N];

long long pw(int u, int p)
{
    long long ret = 1;
    for (int i = 31; i >= 0; i--)
    {
        (ret *= ret) %= MOD;
        if (p >> i & 1)
            (ret *= u) %= MOD;
    }
    return ret;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", a + i);
        inv[i] = (inv[i - 1] + pw(i, MOD - 2)) % MOD;
        (fct *= i) %= MOD;
    }
    for (int i = 1; i <= n; i++)
    {
        long long cur = (inv[n - i + 1] + inv[i] + MOD - 1) % MOD;
        (ans += cur * a[i]) %= MOD;
    }
    printf("%lld", ans * fct % MOD);
}