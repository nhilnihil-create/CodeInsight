#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
const ll INF = 1LL << 60;
const ll MOD = 998244353;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}
template <class C>
void print(const C &c, std::ostream &os = std::cout) {
    std::copy(std::begin(c), std::end(c), std::ostream_iterator<typename C::value_type>(os, " "));
    os << std::endl;
}

struct Combination {
    vector<ll> fac, finv, inv;

    Combination(ll maxN) {
        maxN += 100; // for safety
        fac.resize(maxN + 1);
        finv.resize(maxN + 1);
        inv.resize(maxN + 1);
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (ll i = 2; i <= maxN; ++i) {
            fac[i] = fac[i - 1] * i % MOD;
            inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
            finv[i] = finv[i - 1] * inv[i] % MOD;
        }
    }
    ll operator()(ll n, ll k) {
        if (n < k)
            return 0;
        if (n < 0 || k < 0)
            return 0;
        return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
    }
};


int main() {
    ll n, a, b, k;
    cin >> n >> a >> b >> k;
    Combination nCk(n);
    ll ret = 0;
    for (ll i = 0; i <= n; ++i) {
        ll red = i * a;
        if ((k - red) >= 0 && (k - red) % b == 0) {
            ll ib = (k - red) / b;
            ret = (ret + nCk(n, ib) * nCk(n, i)) % MOD;
        }
    }
    cout << ret << "\n";
    return 0;
}