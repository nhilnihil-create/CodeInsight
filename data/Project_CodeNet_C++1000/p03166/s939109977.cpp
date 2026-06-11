#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > G;
vector<int> dist;

int dfs(int u) {
    if (dist[u] != -1)
        return dist[u];
    
    int res = 0;
    for (auto v : G[u])
        res = max(res, dfs(v)+1);
    
    return dist[u] = res;
}

int main() {
    int n, m;   cin >> n >> m;
    int x, y;   
    G.resize(n);
    dist.resize(n, -1);

    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        G[x-1].push_back(y-1);
    }

    int ans = 0;
    for (int u = 0; u < n; u++) {
        if (dist[u] == -1) {
            ans = max(ans, dfs(u));
        }
        else
            ans = max(ans, dist[u]);
    }

    cout << ans << endl;
    return 0;
}