#include <bits/stdc++.h>

using namespace std;
using Graph = vector<vector<int>>;

int main(void) {
    int n;
    cin >> n;
    vector<int> color(n, -1);
    color[0] = 0;
    Graph g(n), cost(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b, l;
        cin >> a >> b >> l;
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
        cost[a].push_back(l);
        cost[b].push_back(l);
    }
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < g[v].size(); ++i) {
            int u = g[v][i];
            int w = cost[v][i];
            if (color[u] != -1) continue;
            color[u] = (color[v] + w) % 2;
            q.push(u);
        }
    }
    for (auto ans : color) {
        cout << ans << endl;
    }
}