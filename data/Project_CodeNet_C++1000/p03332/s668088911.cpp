#include "bits/stdc++.h"
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

using ll = long long;

const ll MOD = 998244353;

ll mod_pow(ll x, ll n, ll mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return res;
}

int main() {
    ll N, A, B, K, ans = 0;
    cin >> N >> A >> B >> K;
    vector<ll> f(N + 1, 1) ;
    rep(i, N) f[i + 1] = (f[i] * (i + 1)) % MOD;
    rep(i, N + 1) {
        ll x = K - A * i;
        if (x < 0) break;
        if (x % B != 0) continue;
        ll j = x / B;
        if (j > N) continue;
        //cout << i << j << endl;
        ll c1 = ((f[N] * mod_pow(f[i], MOD - 2, MOD)) % MOD * mod_pow(f[N - i], MOD - 2, MOD)) % MOD;
        ll c2 = ((f[N] * mod_pow(f[j], MOD - 2, MOD)) % MOD * mod_pow(f[N - j], MOD - 2, MOD)) % MOD;
        ans = (ans + c1 * c2) % MOD;
    }
    cout << ans << endl;
}