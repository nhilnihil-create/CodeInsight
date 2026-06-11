#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
vector<int> adj[N];
int vis[N] , n , m;

int opp (int node) {
    if (node > n)
        return node - n;
    return node + n;
}

void dfs (int node) {
    if (vis[node])
        return;

    vis[node] = 1;

    dfs(opp(node));
    for (int child : adj[node])
        dfs(child);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m;

    for (int i = 0 ;i < m ;i++) {
        int x , y , z;
        cin >> x >> y >> z;

        if (z&1) {
            adj[opp(x)].push_back(y);
            adj[opp(y)].push_back(x);
        } else {
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
    }

    int ans = 0;
    for (int i = 1 ;i <= n ;i++) {
        if (!vis[i]) {
            ans++;
            dfs(i);
            dfs(opp(i));
        }
    }

    cout << ans;
}
