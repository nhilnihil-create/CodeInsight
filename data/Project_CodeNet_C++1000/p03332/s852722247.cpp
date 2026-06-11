#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
//#include "library/debug.cpp"
using P = pair<ll, ll>;

struct combination {
    ll mod;
    vector<ll> fac, finv, inv;

    combination(int n, ll m)
        : fac(n), finv(n), inv(n) {
        mod = m;
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i < n; i++) {
            fac[i] = fac[i - 1] * i % mod;
            inv[i] = mod - inv[mod % i] * (mod / i) % mod;
            finv[i] = finv[i - 1] * inv[i] % mod;
        }
    }

    ll c(int n, int k) {
        if (n < k)
            return 0;
        if (n < 0 || k < 0)
            return 0;
        return fac[n] * (finv[k] * finv[n - k] % mod) % mod;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, a, b, k;
    cin >> n >> a >> b >> k;
    ll mod = 998244353;
    combination x(700000, mod);
    ll ans = 0;
    for (ll i = 0; i <= n; i++) {
        if ((k - a * i) % b != 0) continue;
        ll j = (k - a * i) / b;
        ans += x.c(n, i) * x.c(n, j);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}