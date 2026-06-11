#include <bits/stdc++.h>
using namespace std;

#define rep(i, m, n) for(int(i) = (int)(m); i < (int)(n); ++i)
#define rep2(i, m, n) for(int(i) = (int)(n)-1; i >= (int)(m); --i)
#define REP(i, n) rep(i, 0, n)
#define REP2(i, n) rep2(i, 0, n)
#define all(hoge) (hoge).begin(), (hoge).end()
#define en '\n'
using ll = long long;
using ull = unsigned long long;
template <class T>
using vec = vector<T>;
template <class T>
using vvec = vector<vec<T>>;
typedef pair<ll, ll> P;
constexpr long long INF = 1LL << 60;
constexpr int INF_INT = 1 << 25;
constexpr long long MOD = (ll)1e9 + 7;
// constexpr long long MOD = 998244353LL;
using ld = long double;
static const ld pi = 3.141592653589793L;
typedef vector<ll> Array;
typedef vector<Array> Matrix;

template <class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

struct Edge {
    ll to, rev;
    long double cap;
    Edge(ll _to, long double _cap, ll _rev) {
        to = _to;
        cap = _cap;
        rev = _rev;
    }
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;

void add_edge(Graph &G, ll from, ll to, long double cap, bool revFlag,
              long double revCap) {
    G[from].push_back(Edge(to, cap, (ll)G[to].size()));
    if(revFlag)
        G[to].push_back(Edge(from, revCap, (ll)G[from].size() - 1));
}

void solve() {
    ll n;
    cin >> n;
    Graph g(n);
    REP(i, n - 1) {
        ll a, b;
        cin >> a >> b;
        add_edge(g, --a, --b, 1, true, 1);
    }

    Array d(n, 0);
    auto dfs = [&](auto &&self, int v, int p) -> void {
        for(auto e : g[v]) {
            if(e.to == p)
                continue;
            d[e.to] = d[v] + 1;
            self(self, e.to, v);
        }
    };

    auto check = [&](int v) -> P {
        d[v] = 0;
        dfs(dfs, v, -1);
        ll ma = 0;
        ll ma_i = 0;
        REP(i, n) {
            if(chmax(ma, d[i]))
                ma_i = i;
        }
        return {ma, ma_i};
    };

    auto leaf = check(0).second;
    auto ma_l = check(leaf).second;
    ll ans = check(ma_l).first + 1;

    if(ans % 3 == 2)
        cout << "Second" << en;
    else
        cout << "First" << en;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
    // ll t;cin>>t;REP(i,t) solve();

    return 0;
}
