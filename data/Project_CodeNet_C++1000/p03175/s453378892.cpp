#include <bits/stdc++.h>
#include "bits/stdc++.h"

using namespace std;

#define int long long

#ifndef bhupixb
    #define var(...)
    #define stl(...)
#endif

#define rep(i,a,b) for (int i = a; i <= (int)b; ++i)
#define f first
#define s second

#define single_test


constexpr int mod = 1e9 + 7;

struct M {
    unsigned v;
    M(long long a = 0) : v((a %= mod) < 0 ? a + mod : a) {}
    M& operator+=(M r) { if ((v += r.v) >= mod) v -= mod; return *this; }
    M& operator-=(M r) { if ((v += mod - r.v) >= mod) v -= mod; return *this; }
    M& operator*=(M r) { v = (uint64_t)v * r.v % mod; return *this; }
};

uint32_t add(M a, M b) { return (a += b).v; }
uint32_t mul(M a, M b) { return (a *= b).v; }
uint32_t sub(M a, M b) { return (a -= b).v; }

const int max_nodes = 1e5 + 3;
using edge = int32_t;
vector<edge> g[max_nodes];
bool vis[max_nodes];
struct graph {
    static void reset(int n) {
        for (int i = 0; i <= n; ++i) {
            g[i].clear();
            vis[i] = false;
        }
    }
    graph(int n) { reset(n); }
    void add_edge(int u, int v) {
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
};

const int maxn = 1e5 + 4;
int dp[maxn][2];

void dfs(int u, int par = -1) {
    for (auto v: g[u]) {
        if (v != par) {
            dfs(v, u);
        }
    }
    int b = 1, w = 1;
    for (int adj: g[u]) {
        if (adj != par) {
            b = mul(b, dp[adj][1]);
            w = mul(w, add(dp[adj][0], dp[adj][1]));
        }
    }
    var(u, par, b, w);
    dp[u][0] = b;
    dp[u][1] = w;

}

void solve() {
    int n;
    cin >> n;
    graph ins(n);
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        ins.add_edge(u, v);
    }
    int ans = 0;
    for (int i = 1; i < 2; ++i) {
        memset(dp, 0, sizeof dp);
        dfs(i, -1);
        ans = add(ans, add(dp[i][0], dp[i][1]));
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
    #ifndef single_test
        cin >> t;
    #endif
    for (int i = 1; i <= t; ++i) {
        // cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}