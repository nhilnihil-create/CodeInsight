#pragma GCC optimize ("O3")

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <prettyprint.hpp>
#define debug(...)  cerr << "[" << #__VA_ARGS__ << "]: ", d_err(__VA_ARGS__);
#else
#define debug(...) 83;
#endif

void d_err() {
    cerr << endl;
}

template <typename H, typename... T>
void d_err(H h, T... t) {
    cerr << h << " ";
    d_err(t...);
}

template <typename T>
void print(T x) {
    cout << x << "\n";
}

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define REVFOR(i, m, n) for (int i = (n - 1); i >= (m); --i)
#define REP(i, n) FOR(i, 0, n)
#define REVREP(i, n) REVFOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define bcnt __builtin_popcountll

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> Pll;
typedef pair<int,int> Pin;

ll INF = 1e16;
int inf = 1e9;

void chmax(ll& x, ll y) {
    if (x < y) x = y;
}

struct UnionFind {
    vector<int> par;

    UnionFind(int n): par(n, -1) {}
    void init(int n) { par.assign(n, -1); }

    int root(int x) {
        if (par[x] < 0) return x;
        return par[x] = root(par[x]);
    }

    int issame(int x, int y) {
        return root(x) == root(y);
    }

    bool merge(int x, int y) {
        x = root(x); y = root(y);

        if (x == y) return false;

        // merge by size
        // force size of x to be bigger than that of y
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;

        return true;
    }

    int size(int x) {
        return -par[root(x)];
    }
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, m; cin >> n >> m;

    vector<int> a(m), b(m);
    REP(i, m) cin >> a[i] >> b[i];

    int ans = 0;
    REP(ng, m) {
        UnionFind uf(n + 1);

        REP(j, m) {
            if (j == ng) continue;
            uf.merge(a[j], b[j]);
        }

        ll s = 0;
        REP(i, n) chmax(s, uf.size(i));
        if (s != n) ans++;
    }

    print(ans);


}