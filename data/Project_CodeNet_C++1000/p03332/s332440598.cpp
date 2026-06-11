#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

constexpr ll infl = 10000000000000000LL;
constexpr int inf = 1000000000;

template <int MaxN = 100000, long long mod = 1000000007LL>
class Modlib {
    long long _fact[MaxN + 1];
    long long _fact_inv[MaxN + 1];

public:
    // x^n
    long long pow(long long x, long long n) const {
        long long ret = 1LL;
        long long t = x % mod;
        while (n > 0) {
            if (n & 1LL) {
                ret *= t;
                ret %= mod;
            }
            t *= t;
            t %= mod;
            n >>= 1;
        }
        return ret;
    }
    // xの逆元
    // https://qiita.com/drken/items/3b4fdf0a78e7a138cd9a
    constexpr long long inv(long long a) const {
        long long b = mod, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b;
            a ^= b;
            b ^= a;
            a ^= b;

            u -= t * v;
            u ^= v;
            v ^= u;
            u ^= v;
        }
        u %= mod;
        if (u < 0)
            u += mod;
        return u;
    }
    // n!
    long long fact(long long n) const {
        return _fact[n];
    }
    // nPk
    long long perm(long long n, long long k) const {
        return fact(n) * _fact_inv[n - k] % mod;
    }
    // nCk
    long long comb(long long n, long long k) const {
        return perm(n, k) * _fact_inv[k] % mod;
    }

    constexpr Modlib() : _fact{}, _fact_inv{} {
        _fact[0] = _fact[1] = 1LL;
        for (int i = 2; i <= MaxN; ++i) {
            _fact[i] = _fact[i - 1] * i % mod;
        }
        _fact_inv[MaxN] = inv(_fact[MaxN]);
        for (int i = MaxN - 1; i >= 0; --i) {
            _fact_inv[i] = _fact_inv[i + 1] * (i + 1) % mod;
        }
    }
};

constexpr ll mod = 998244353LL;
constexpr auto modlib = Modlib<300000, mod>();

int main() {
    ll n, a, b, k;
    cin >> n >> a >> b >> k;
    ll ans = 0;
    for (ll i = 0; i <= n; ++i) {
        ll j = k - a * i;
        if (j % b != 0)
            continue;
        j /= b;
        if (!(0 <= j && j <= n))
            continue;
        ans += modlib.comb(n, i) * modlib.comb(n, j) % mod;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
