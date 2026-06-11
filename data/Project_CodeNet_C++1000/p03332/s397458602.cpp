#include <bits/stdc++.h>
using namespace std;
using ll = long long;
// const long double PI = acos(-1);
constexpr int inf = 1e9;
constexpr ll INF = 2e18;
// constexpr ll MOD = 1e9+7;
constexpr ll MOD = 998244353;

ll n,a,b,k;
ll kai[300010];

void input() {
    cin >> n >> a >> b >> k;
}

ll mypow(ll _a, ll _b) {
    if (_b == 0) return 1;
    if (_b == 1) return _a;
    ll ans = mypow(_a, _b / 2);
    ans = ans * ans % MOD;
    if (_b & 1) ans = ans * _a % MOD;
    return ans;
}

ll inv(ll _k) {
    return mypow(_k, MOD - 2);
}

ll C(ll _k, ll _n) {
    return kai[_n] * inv(kai[_n - _k]) % MOD * inv(kai[_k]) % MOD;
}

void solve() {

    kai[0] = 1;
    kai[1] = 1;
    for (ll i = 2; i <= n; i++) {
        kai[i] = kai[i-1] * i % MOD;
    }

    ll ans = 0;
    for (ll na = 0; na <= n; na++) {
        ll nb = (k - na * a) / b;
        if (nb * b + na * a == k && 0 <= nb && nb <= n) {
            ans += C(na, n) * C(nb, n) % MOD;
            ans %= MOD;
            // cout << na << " " << nb << " " << C(na, n) << " " << C(nb, n) << endl;
        }
    }
    cout << ans << endl;
}

int main(int argc, char *argv[]) {
    input();
    solve();
    return 0;
}
