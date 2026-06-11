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

void dfs(vector<ll> &ki,vector<vector<ll>> &z,ll now, vector<ll> &ans, vector<ll> &seen) {
    seen[now] = 1;
    for (int i = 0; i < z[now].size(); i++) {
        if (seen[z[now][i]] == 0) {
            dfs(ki, z, z[now][i], ans, seen);
            ki[now] += ki[z[now][i]];
            ans[now] = max(ans[now], ki[z[now][i]]);
        }
    }
    ki[now]++;
    ll p = ki.size();
    if (now != 0)ans[now] = max(ans[now],p - ki[now]);
    return;
}

int main() {
    ll n, c;
    cin >> n >> c;
    vector<vector<ll>> z(c,vector<ll>(100001));
    for (int i = 0; i < n; i++) {
        ll a, b, d;
        cin >> a >> b >> d;
        for (int j = a - 1; j < b; j++) {
            z[d - 1][j] = 1;
        }
    }
    ll ans = 0;
    for (int i = 0; i < 100001; i++) {
        ll zans = 0;
        for (int j = 0; j < c; j++) {
            zans += z[j][i];
        }
        ans = max(ans, zans);
    }
    cout << ans << endl;
}