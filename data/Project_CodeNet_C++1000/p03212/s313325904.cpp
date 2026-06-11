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
#include <iomanip>
#include <float.h>
#include <math.h>
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

ll ll_gcd(ll a, ll b) {
    if (a < b) return ll_gcd(b, a);
    ll r;
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
    ll n;
    cin >> n;
    ll k = n;
    ll b = 0;
    vector<ll>ans;
    while (k > 0) {
        b++;
        k /= 10;
    }
    for (int d = 1; d < b + 1; d++) {
        for (int i = 0; i < modpow(3, d, 1000000007); i++) {
            ll t = i;
            ll zans = 0;
            for (int j = 0; j < d; j++) {
                zans += modpow(10, j, 1000000007) * ((t % 3) * 2 + 3);
                t /= 3;
            }
            if (zans <= n)ans.push_back(zans);
        }
    }
    ll anss = 0;
    for (int i = 0; i < ans.size(); i++) {
        ll x = 0;
        ll c = 0;
        ll v = 0;
        while (ans[i] > 0) {
            if (ans[i] % 10 == 3)x++;
            if (ans[i] % 10 == 5)c++;
            if (ans[i] % 10 == 7)v++;
            ans[i] /= 10;
        }
        if (x * c * v > 0)anss++;
    }
    cout << anss << endl;
}