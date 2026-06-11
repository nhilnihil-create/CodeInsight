#include <bits/stdc++.h>
#include "bits/stdc++.h"

using namespace std;

// #define int long long

#ifndef bhupixb
    #define var(...)
    #define stl(...)
#endif

#define rep(i,a,b) for (int i = a; i <= (int)b; ++i)
#define f first
#define s second

#define single_test

const int max_nodes = 2e5;
using edge = int32_t;
vector<edge> g[max_nodes];
bool vis[max_nodes];
struct digraph {
    int N;
    vector<int> topo;
    static void reset(int n) {
        for (int i = 0; i <= n; ++i) {
            g[i].clear();
            vis[i] = 0;
        }
    }
    digraph(int n) : N(n) { reset(n); }
    // return true if graph is DAG i.e. topo sort exists

    void add_edge(int u, int v) {
        g[u].emplace_back(v);
    }
};

const int maxn = 1e5 + 4;
int dp[maxn];

void dfs(int u, int par = -1) {
    vis[u] = 1;
    for (auto v: g[u]) {
        if (!vis[v]) {
            dfs(v, u);
        }
        dp[u] = max(dp[u], 1 + dp[v]);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    digraph ins(n);
    while (m--) {
        int u, v;
        cin >> u >> v;
        ins.add_edge(u, v);
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i);
        }
    }
    cout << *max_element(dp + 1, dp + 1 + n) << '\n';
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