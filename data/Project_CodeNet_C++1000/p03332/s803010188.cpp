#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
ll MOD = 998244353;
const ll N = 1e7+10;
ll f[N], rf[N];
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
    for(int i = 1; i < N; i++) f[i] = (f[i - 1] * i) % MOD;
    rf[N - 1] = inv(f[N - 1]);
    for(int i = N-2; i >= 0; i--) rf[i] = (rf[i + 1] * (i + 1)) % MOD;
}
ll C(int n, int k) {
    if(k < 0 || n < k) return 0;
    ll a = f[n]; // = n!
    ll b = rf[n-k]; // = (n-k)!^(-1)
    ll c = rf[k]; // = k!^(-1)
    ll bc = (b * c) % MOD;
    return (a * bc) % MOD;
}
ll p(int n, int k) {
    if (k < 0 || n < k) return 0;
    ll a = f[n]; // = n!
    ll b = rf[n - k]; // = (n-k)!^(-1)
    return (a * b) % MOD;
}
ll H(int n, int k) {
    if (n == 0 && k == 0) return 1;
    return C(n + k - 1, k);
}
ll mod_pow(ll x, ll n)
{
    ll res = 1;
    while(n > 0)
    {
        if(n & 1)
        {
            res = res * x % MOD;
        }
        x = x * x % MOD;
        n >>= 1;
    }
    return res;
}
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
        ll num = k - a * i;
        if(num < 0) break;
        if(num % b) continue;
        add(ans, C(n, i) * C(n, num/b) % MOD);
    }
    add(ans, MOD);
    cout << ans << endl;
}
