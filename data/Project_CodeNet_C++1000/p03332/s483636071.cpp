#include <iostream>
#include <algorithm>
#include <set>
#include <vector>

using namespace std;

long long ans = 0;
long long MOD = 998244353;

long long fact[500000];
long long ufact[500000];

long long inq(long long a, long long b)
{
    if (b == 0) return 1;
    long long l = inq(a, b / 2);
    if (b % 2) return l * l % MOD * a % MOD;
    return l * l % MOD;
}
long long cnk(long long n, long long k)
{
    if (k <= n && k >= 0)
        return (fact[n] * ufact[n - k] % MOD * ufact[k] % MOD);
    return 0;
}
int main()
{
    fact[0] = 1, ufact[0] = 1;
    for (int i = 1; i < 500000; i++) fact[i] = fact[i - 1] * i % MOD, ufact[i] = inq(fact[i], MOD - 2);
    long long n, a, b, k;
    cin >> n >> a >> b >> k;
    for (int i = 0; i <= n; i++)
    {
        long long summ = a * i;
        long long j = (k - summ) / b;
        if (j * b != k - summ) continue;
        ans += cnk(n, i) * cnk(n, j);
        ans %= MOD;
    }
    cout << ans;
}
