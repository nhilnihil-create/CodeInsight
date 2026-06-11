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
    vector<ll> z(n);
    vector<ll> x(n);
    for (int i = 0; i < n; i++) {
        cin >> z[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    ll ans = 0;
    for (int i = 0; i < 30; i++) {
        ll zans = 0;
        vector<ll> ari;
        vector<ll> nasi;
        ll u = (1ull << i);
        for (int j = 0; j < n; j++) {
            if (z[j] & (1ull << i))ari.push_back(z[j] % u);
            else nasi.push_back(z[j] % u);
        }
        sort(ari.begin(), ari.end());
        sort(nasi.begin(), nasi.end());
        for (int j = 0; j < n; j++) {
            ll ok = -1;
            ll ng = ari.size();
            while (ng - ok > 1) {
                ll mid = (ok + ng) / 2;
                if (x[j]%u + ari[mid] < u)ok = mid;
                else ng = mid;
            }
            if(x[j] & (1ull << i))zans+=ari.size() - (ok + 1);
            else zans += ok + 1;
            ll oks = -1;
            ll ngs = nasi.size();
            while (ngs - oks > 1) {
                ll mids = (oks + ngs) / 2;
                if (x[j]%u + nasi[mids] < u)oks = mids;
                else ngs = mids;
            }
            if (x[j] & (1ull << i))zans += oks + 1;
            else zans += nasi.size()-(oks+1);
        }

        if (zans % 2 == 1)ans |= (1ull << i);
    }
    cout << ans << endl;
}