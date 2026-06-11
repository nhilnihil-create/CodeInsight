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

template <typename T>
T ceilDiv(T a, T b) {
    return a > 0 && b > 0 ? (a + b - 1) / b : a / b;
}

template <typename T>
T gcd(T a, T b) {
    return b != 0 ? gcd(b, a % b) : a;
}

template <int MaxN = 100000, long long mod = 1000000007LL>
class Modlib {
    long long _fact[MaxN + 1];

public:
    // ax + by = gcd(a, b)の解(x, y)を1つ求める.
    // 参考: https://qiita.com/drken/items/b97ff231e43bce50199a
    pair<long long, long long> exgcd(long long a, long long b) const {
        if (b == 0) {
            return {1, 0};
        } else {
            const auto &s = exgcd(b, a % b);
            return {s.second, s.first - a / b * s.second};
        }
    }

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
    long long inv(long long x) const {
        // x * s + mod * t = 1を満たす(s, t)のs
        return (exgcd(x, mod).first % mod + mod) % mod;
    }
    // n!
    long long fact(long long n) const {
        return _fact[n];
    }
    // nPk
    long long perm(long long n, long long k) const {
        return fact(n) * inv(fact(n - k)) % mod;
    }
    // nCk
    long long comb(long long n, long long k) const {
        return perm(n, k) * inv(fact(k)) % mod;
    }

    constexpr Modlib() : _fact{} {
        _fact[0] = _fact[1] = 1LL;
        for (int i = 2; i <= MaxN; ++i) {
            _fact[i] = _fact[i - 1] * i % mod;
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