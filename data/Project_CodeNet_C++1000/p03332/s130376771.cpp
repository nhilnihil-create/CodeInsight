#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = s; i < (int)(n); i++)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
ll mod = 998244353;
//---------------------------------------------------------------------------------------------------
ll f[301010], rf[301010];
ll inv(ll x)
{
    ll res = 1;
    ll k = mod - 2;
    ll y = x;
    while (k)
    {
        if (k & 1)
            res = (res * y) % mod;
        y = (y * y) % mod;
        k /= 2;
    }
    return res;
}
void init()
{
    f[0] = 1;
    rep(i, 1, 301010) f[i] = (f[i - 1] * i) % mod;
    rep(i, 0, 301010) rf[i] = inv(f[i]);
}
//---------------------------------------------------------------------------------------------------
ll C(int n, int k)
{
    ll a = f[n];      // = n!
    ll b = rf[n - k]; // = (n-k)!
    ll c = rf[k];     // = k!

    ll bc = (b * c) % mod;

    return (a * bc) % mod;
}

int main()
{
    init();
    ll n, a, b, k;
    cin >> n >> a >> b >> k;
    ll ans = 0;
    for (ll i = 0; i < n + 1; i++)
    {
        if (a * i > k)
            break;
        if ((k - a * i) % b == 0)
        {
            ll t = (k - a * i) / b;
            if (t > n)
                continue;
            ans += C(n, i) * C(n, t);
            ans %= mod;
        }
    }
    cout << ans % mod << endl;
}