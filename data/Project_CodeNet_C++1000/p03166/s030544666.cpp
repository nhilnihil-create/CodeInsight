#include <bits/stdc++.h>
using namespace std;

int memo[100'000+5];      /// memo[i] = max length path starting from node i

vector<int> adj[100'000+5];
bool vis[100'000+5];

int dp(int u){
    if(vis[u]) return memo[u];

    vis[u] = true;
    for(int v : adj[u]){
        memo[u] = max(memo[u], dp(v)+1);
    }

    return memo[u];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin>>n>> m;

    for(int i = 0; i<m; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    int ans = 0;
    for(int i = 1; i<=n; i++){
        ans = max(ans, dp(i));
    }

    cout<<ans<<endl;

    return 0;
}

