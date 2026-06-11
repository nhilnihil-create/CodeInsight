#include <iostream>
#include <vector>

using namespace std;

vector<int> topo;
vector<int> seen;
vector<vector<int> > G;

void topological_sort(int s) {
    seen[s] = 1;
    for (int i = 0; i < G[s].size(); i++) {
        int u = G[s][i];
        if (seen[u])
            continue;
        
        topological_sort(u);
    }
    topo.push_back(s);
}

int main() {
    int n, m;   cin >> n >> m;
    seen.resize(n, 0);
    G.resize(n);
    for (int i = 0; i < m; i++) {
        int x, y;   cin >> x >> y;
        x--;
        y--;
        G[x].push_back(y);
    }

    for (int i = 0; i < n; i++) {
        if (!seen[i])
            topological_sort(i);
    }

    for (int i = 0; i < n/2; i++) {
        swap(topo[i], topo[n-1-i]);
    }

    vector<int> dp(n, -1);
    for (int i = 0; i < n; i++) {
        int u = topo[i];
        
        if (dp[u] == -1)
            dp[u] = 0;
        for (int j = 0; j < G[u].size(); j++) {
            int v = G[u][j];
            dp[v] = max(dp[v], dp[u] + 1);
        }
    }
    

    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(dp[i], ans);

    cout << ans << endl;
    return 0;
}