#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <functional>
#include <ctime>
#include <cmath>
#include <limits>
#include <numeric>
#include <type_traits>
using namespace std;
using ll = long long;

unsigned euclidean_gcd(unsigned a, unsigned b) {
    if (a < b) return euclidean_gcd(b, a);
    unsigned r;
    while ((r = a % b)) {
        a = b;
        b = r;
    }
    return b;
}

class UnionFind {
public:
    vector <ll> par;
    vector <ll> siz;
    UnionFind(ll sz_) : par(sz_), siz(sz_, 1LL) {
        for (ll i = 0; i < sz_; ++i) par[i] = i;
    }
    void init(ll sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1LL);
        for (ll i = 0; i < sz_; ++i) par[i] = i;
    }
    ll root(ll x) {
        while (par[x] != x) {
            x = par[x] = par[par[x]];
        }
        return x;
    }
    bool merge(ll x, ll y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }

    bool issame(ll x, ll y) {
        return root(x) == root(y);
    }

    ll size(ll x) {
        return siz[root(x)];
    }
};

long long modpow(long long a, long long n, long long mod) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}

long long modinv(long long a, long long mod) {
    return modpow(a, mod - 2, mod);
}

int main() {
    ll a, n, b, k;
    cin >> n >> a >> b >> k;
    ll ans = 0;
    vector<ll> bik(n+1);
    bik.at(0) = 1;

    for (int i = 0; i < n; i++) {
        bik.at(i + 1) = bik.at(i) * (i + 1) % 998244353;
    }

    for (int i = 0; i < n+1; i++) {
        if ((k - a * i) % b == 0 && k >= a * i && (k - a * i) / b <= n) {
            ll z = (k - a * i) / b;
            ans += bik.at(n) * modinv(bik.at(i), 998244353) % 998244353 * modinv(bik.at(n - i), 998244353) % 998244353 * bik.at(n) % 998244353 * modinv(bik.at(z), 998244353) % 998244353 * modinv(bik.at(n - z), 998244353) % 998244353;
            ans %= 998244353;
        }
    }
    cout << ans << endl;
}