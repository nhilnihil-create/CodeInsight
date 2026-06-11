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
#include <fstream>
#include <cmath>
#include <limits>
#include <chrono>
#include <numeric>
#include <type_traits>
#include <iomanip>
#include <float.h>
#include <math.h>
#include <cassert>
#pragma warning (disable: 4996)
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

struct UnionFind {
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
    if (n < 0)return 0;
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

ll merge_cnt(vector<ll>& a) {
    int n = a.size();
    if (n <= 1) { return 0; }

    ll cnt = 0;
    vector<ll> b(a.begin(), a.begin() + n / 2);
    vector<ll> c(a.begin() + n / 2, a.end());

    cnt += merge_cnt(b);
    cnt += merge_cnt(c);

    int ai = 0, bi = 0, ci = 0;
    while (ai < n) {
        if (bi < b.size() && (ci == c.size() || b[bi] <= c[ci])) {
            a[ai++] = b[bi++];
        }
        else {
            cnt += n / 2 - bi;
            a[ai++] = c[ci++];
        }
    }
    return cnt;
}

struct edge { ll to, cost; };
typedef pair<ll, ll> P;
struct graph {
    ll V;
    vector<vector<edge> > G;
    vector<ll> d;

    graph(ll n) {
        init(n);
    }

    void init(ll n) {
        V = n;
        G.resize(V);
        d.resize(V);
        for (int i = 0; i < V; i++) {
            d[i] = 2000000000000000000;
        }
    }

    void add_edge(ll s, ll t, ll cost) {
        edge e;
        e.to = t, e.cost = cost;
        G[s].push_back(e);
    }

    void dijkstra(ll s) {
        for (int i = 0; i < V; i++) {
            d[i] = 2000000000000000000;
        }
        d[s] = 0;
        priority_queue<P, vector<P>, greater<P> > que;
        que.push(P(0, s));
        while (!que.empty()) {
            P p = que.top(); que.pop();
            ll v = p.second;
            if (d[v] < p.first) continue;
            for (auto e : G[v]) {
                if (d[e.to] > d[v] + e.cost) {
                    d[e.to] = d[v] + e.cost;
                    que.push(P(d[e.to], e.to));
                }
            }
        }
    }
};



int main() {
    ll h, w, d;
    cin >> h >> w >> d;
    vector<pair<int, int>> z(h * w);
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            ll a;
            cin >> a;
            z[a - 1] = make_pair(i, j);
        }
    }
    vector<int> x(h * w);
    for (int i = d; i < h*w; i++) {
        x[i] = x[i - d] + abs(z[i].first - z[i - d].first) + abs(z[i].second - z[i - d].second);
    }
    ll q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        ll a, b;
        cin >> a >> b;
        cout << x[b-1] - x[a-1] << endl;
    }
}