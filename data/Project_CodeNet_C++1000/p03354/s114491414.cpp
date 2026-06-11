#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define rrep(i, n) for(int i=n-1; i>=0; i--)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define ALL(v) v.begin(),v.end()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9+7;
const double EPS = 1e-10;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int MAX = 100010;

struct UnionFind {
    vector<int> par;

    UnionFind(int n) {
        par.resize(n);
        rep(i, n) par[i] = i;
    }

    int root(int x) {
        if (par[x] == x) return x;
        par[x] = root(par[x]);
        return par[x];
    }

    void unite(int x, int y) {
        int rx = root(x);
        int ry = root(y);
        if (rx == ry) return;
        par[ry] = rx;
    }

    bool same(int x, int y) {
        return root(x) == root(y);
    }
};

int main() {
    int n, m, p[MAX];
    cin >> n >> m;
    rep(i, n) cin >> p[i];
    rep(i, n) p[i]--;

    UnionFind uf(n);

    rep(i, m) {
        int x, y; cin >> x >> y;
        x--; y--;
        uf.unite(p[x], p[y]);
    }

    int ans = 0;
    rep(i, n) {
        if (uf.same(i, p[i])) ans++;
    }
    cout << ans << endl;
}
