#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for(int(i) = 0; (i) < (n); (i)++)
#define FOR(i, m, n) for(int(i) = (m); (i) < (n); (i)++)
#define All(v) (v).begin(), (v).end()
#define pb push_back
#define MP(a, b) make_pair((a), (b))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int INF = 1 << 30;
const ll LINF = 1LL << 60;
const int MOD = 1e9 + 7;

// UnionFind
struct UnionFind {
    vector<ll> par;
    vector<ll> siz;

    UnionFind(ll N) : par(N), siz(N, 1LL) {
        for(int i = 0; i < N; i++)
            par[i] = i;
    }
    int root(int x) {
        if(par[x] == x)
            return x;
        return par[x] = root(par[x]);
    }
    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if(rx == ry)
            return;
        if(siz[rx] < siz[ry])
            swap(rx, ry);
        siz[rx] += siz[ry];
        par[ry] = rx;
    }
    bool same(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }
    ll size(ll x) { return siz[root(x)]; }
};

int main() {
    int N, M;
    cin >> N >> M;
    UnionFind uf(N);
    rep(i, M) {
        int x, y, z;
        cin >> x >> y >> z;
        x--, y--;
        uf.unite(x, y);
    }
    set<int> par;
    rep(i, N) { par.insert(uf.root(i)); }
    cout << par.size() << endl;
    return 0;
}