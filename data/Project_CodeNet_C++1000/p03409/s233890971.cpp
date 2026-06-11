
#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;

#define rep(a,n) for(ll a = 0;a < n;a++)

static const ll INF = 1e18;
static const ll mod = 1e9+7;

template<typename T>
static inline void chmin(T& ref, const T  value) {
    if (ref > value) ref = value;
}

template<typename T>
static inline void chmax(T& ref, const T value) {
    if (ref < value) ref = value;
}
struct BMatch {
    const vector<vector<int>>& g;
    const int n;
    vector<int> match;
    vector<bool> used;

    BMatch(const vector<vector<int>>& g_) : g(g_), n(g_.size()) { }

    bool dfs(int v) {
        used[v] = true;
        for (int i = 0; i < g[v].size(); i++) {
            int u = g[v][i], w = match[u];
            if (w < 0 || !used[w] && dfs(w)) {
                match[v] = u;
                match[u] = v;
                return true;
            }
        }
        return false;
    }

    int solve() {
        match.assign(n, -1);
        used.assign(n, false);
        int res = 0;
        for (int v = 0; v < n; v++) {
            if (match[v] < 0) {
                used.assign(n, false);
                if (dfs(v)) res++;
            }
        }
        return res;
    }
};

int main() {
    int n;
    cin >> n;
    vector<P> red(n), blue(n);
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        red[i] = { x,y };
    }
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        blue[i] = { x,y };
    }
    vector<vector<int>> graph(2*n);
    rep(i, n) {
        rep(j, n) {
            auto r = red[i];
            auto b = blue[j];
            if (r.first < b.first && r.second < b.second) {
                graph[i].push_back(n + j);
                graph[n+j].push_back(i);
            }
        }
    }
    BMatch match(graph);
    auto ans = match.solve();
    cout << ans << endl;
    return 0;
}
