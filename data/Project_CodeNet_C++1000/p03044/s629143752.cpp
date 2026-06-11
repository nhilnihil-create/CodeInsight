#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<pair<int, int>>>& g, int start,
         vector<int>& cost) {
    for (auto & elm : g[start]) {
        if(cost[elm.first] != -1) continue;
        cost[elm.first] = (cost[start] + elm.second) % 2;
        dfs(g, elm.first, cost);
    }
}

int main(){
    int n; cin >> n;

    vector<vector<pair<int, int>>> g(n);
    for (auto i = 0; i < n - 1; i++) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        g[u].emplace_back(v, w); g[v].emplace_back(u, w);
    }

    vector<int> cost(n, -1);
    cost[0] = 0;
    dfs(g, 0, cost);

    for (auto i = 0; i < n; i++) cout << cost[i] << endl;
    return 0;
}