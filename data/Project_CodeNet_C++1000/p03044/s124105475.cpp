#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<pair<int, int64_t>>>& g, int start,
         vector<int64_t>& cost) {
    for (auto & elm : g[start]) {
        if(cost[elm.first] != -1) continue;
        cost[elm.first] = cost[start] + elm.second;
        dfs(g, elm.first, cost);
    }
}

int main(){
    int n; cin >> n;

    vector<vector<pair<int, int64_t>>> g(n);
    for (auto i = 0; i < n - 1; i++) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        g[u].emplace_back(v, w); g[v].emplace_back(u, w);
    }

    vector<int64_t> cost(n, -1);
    cost[0] = 0;
    dfs(g, 0, cost);

    vector<int> p;
    for (auto i = 0; i < n; i++) {
//        cout << cost[i] << " ";
        if(cost[i] % 2 == 0) cout << 1 << endl;
        else cout << 0 << endl;
    }

    return 0;
}