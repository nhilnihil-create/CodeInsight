#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0);

const int MAXN = 1e5 + 5;

int n, m, d[MAXN];
vector<int> G[MAXN];

void dfs(int u) {
    d[u] = 1;
    for (int v : G[u]) {
        if (!d[v]) {
            dfs(v);
        }
        d[u] = max(d[u], d[v] + 1);
    }
}

int main() {
    IOS

    cin >> n >> m;
    
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        G[x].push_back(y);
    }

    for (int i = 1; i <= n; i++) {
        if (!d[i]) {
            dfs(i);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, d[i]);        
    }
    cout << ans - 1 << '\n';
}