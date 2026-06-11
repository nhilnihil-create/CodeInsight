#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

vector<vector<int>> g;
vector<int> color;

bool is_bipartite(int u) {
    for (int v: g[u]) {
        if (color[v] != -1) {
            if (color[v] == color[u]) return false;
        } else {
            color[v] = color[u] ^ 1;
            if (!is_bipartite(v)) return false;
        }
    }
    return true;
}

int main() {
    int V, E; cin >> V >> E;
    g.resize(V);
    for (int i = 0; i < E; i++) {
        int a, b; cin >> a >> b; a--; b--;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    color.assign(V, -1);
    color[0] = 0;
    ll ans = 0;
    if (!is_bipartite(0)) {
        ans = 1LL * V * (V - 1) / 2;
    } else {
        for (int i = 0; i < V; i++) ans += color[i];
        ans *= V - ans;
    }
    ans -= E;
    cout << ans << endl;
    return 0;
}