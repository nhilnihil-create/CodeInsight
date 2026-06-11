#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
struct DiameterForEdge {
    using Edge = pair<int, T>;
    vector<T> dp;
    vector<vector<Edge>> g;
    DiameterForEdge(int n) : dp(n), g(n) { }
    void add_edge(int u,int v, T c) {
        g[u].emplace_back(v, c);
        g[v].emplace_back(u, c);
    }
    void dfs(int u, int p, int &s) {
        if (p < 0) dp[u] = T(0);
        if (dp[s] < dp[u]) s = u;
        for (Edge &e: g[u]) if (e.first != p) {
            dp[e.first] = dp[u] + e.second;
            dfs(e.first, u, s);
        }
    }
    pair<int, int> endPoints() {
        int s = 0; dfs(s, -1, s);
        int t = s; dfs(t, -1, t);
        return {s, t};
    }
    T build() {
        int t = endPoints().second;
        return dp[t];
    }
    vector<T> distance(int v) {
        dfs(v, -1, v);
        return dp;
    }
    vector<T> farthest() {
        int t = endPoints().second;
        auto ds = dp;
        auto dt = distance(t);
        for (int i = 0; i < ds.size(); i++) ds[i] = max(ds[i], dt[i]);
        return ds;
    }
};

int main() {
    int n; cin >> n;
    DiameterForEdge<int> g(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b; a--, b--;
        g.add_edge(a, b, 1);
    }
    int diam = g.build();
    cout << ((diam % 3 == 1) ? "Second" : "First") << endl;
    return 0;
}