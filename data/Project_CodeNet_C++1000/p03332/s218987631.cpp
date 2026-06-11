#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//---------------------------------------------------------------------------------------------------
ll MOD = 998244353;
ll f[301010], rf[301010];
ll inv(ll x) {
    ll res = 1;
    ll k = MOD - 2;
    ll y = x;
    while (k) {
        if (k & 1) res = (res * y) % MOD;
        y = (y * y) % MOD;
        k /= 2;
    }
    return res;
}
void init() {
    f[0] = 1;
    for(int i = 1; i < 301010; i++) f[i] = (f[i - 1] * i) % MOD;
    for(int i = 0; i < 301010; i++) rf[i] = inv(f[i]);
}
ll C(int n, int k) {
    if(n < k) return 0;
    ll a = f[n]; // = n!
    ll b = rf[n-k]; // = (n-k)!
    ll c = rf[k]; // = k!

    ll bc = (b * c) % MOD;

    return (a * bc) % MOD;
}
//---------------------------------------------------------------------------------------------------

void add(ll &a, ll b)
{
    a = (a+b) % MOD;
}

int main()
{
    init();
    ll n, a, b, k;
    cin >> n >> a >> b >> k;

    ll ans = 0;
    for(int i = 0; i <= n; i++)
    {
        ll v = k - a*i;
        if(v < 0 || v % b != 0) continue;
        ll num = v / b;
        add(ans, C(n, i) * C(n, num));
    }
    cout << (ans+MOD)%MOD << endl;
}
