#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

struct edge { int to, cost; };

vector<edge> g[101010];
int color[101010];

void dfs(int u, int pre, ll dist) {
    for (auto e : g[u]) {
        if (e.to == pre) continue;
        dfs(e.to, u, dist + e.cost);
    }
    color[u] = dist % 2;
}

int main() {
    fill(color, color + 101010, -1);
    ll n;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        g[u].push_back({ v, w });
        g[v].push_back({ u, w });
    }
    dfs(0, -1, 0);
    for (int i = 0; i < n; i++) {
        cout << color[i] << endl;
    }
}