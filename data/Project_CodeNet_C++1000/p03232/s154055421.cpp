#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
#define ll long long
const ll mod = 1e9 + 7;
ll n, a[maxn], fac[maxn], inv[maxn];
ll qpow(ll x, ll n)
{
    ll ans = 1;
    while (n)
    {
        if (n & 1) ans = ans * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return ans % mod;
}
void slove()
{
    cin >> n;
    for (int i = 1; i <= n; ++ i)
        cin >> a[i];
    fac[1] = 1; fac[0] = 1, inv[1] = 1;
    for (ll i = 2; i <= n; ++ i)
    {
        fac[i] = fac[i - 1] * i % mod;
        inv[i] = (inv[i - 1] + qpow(i, mod - 2)) % mod;
    }
    ll ans = 0;
    for (int i = 1; i <= n; ++ i)
    {
        ll pre = i, sub = n - i + 1;
        ans += a[i] * (inv[pre] + inv[sub]) % mod;
        ans = (ans + mod - a[i]) % mod;
    }
    cout << ans * fac[n] % mod << endl;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    slove();
    return 0;
}
