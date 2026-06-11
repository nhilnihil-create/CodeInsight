#include <vector>
#include <iostream>
using namespace std;

vector<int> adj[100100];
bool dp[2][100100];

void dfs(int i, int v) {
    dp[i][v] = true;
    const int j = 1 - i;
    for (int u : adj[v]) {
        if (dp[j][u]) continue;
        dfs(j, u);
    }
}

int main() {
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, 0);
    long long c1 = 0, c2 = 0, c12 = 0;
    for (int i = 0; i < n; i++) {
        c12 += (dp[0][i] && dp[1][i]);
        c1 += dp[1][i];
        c2 += dp[0][i];
    }
    cout << c1 * c2 - c12 * (c12 + 1) / 2 - m << endl;
}
