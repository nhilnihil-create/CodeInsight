#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
vector<pair<int , int> > adj[N];
int col[N];

void dfs (int node , int par , long long s) {
    col[node] = s % 2 == 0;
    for (auto &e : adj[node])
        if (e.first != par)
            dfs(e.first , node , s + e.second);
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.in" , "r" , stdin);
#endif
    int n;
    cin >> n;

    for (int i = 0 ;i < n - 1 ;i++) {
        int u , v , w;
        cin >> u >> v >> w;
        adj[u].push_back({v , w});
        adj[v].push_back({u , w});
    }

    dfs(1 , 1 , 0);

    for (int i = 1 ;i <= n ;i++)
        cout << col[i] << '\n';
}
