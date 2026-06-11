#include <bits/stdc++.h>
using namespace std;
#define LIM 100000
#define pii pair<int, int>
#define ff  first
#define ss  second

vector<int> adj[LIM+5];
int dp[LIM+5];
bool vis[LIM+5];

int f(int u){
    if(vis[u]) return dp[u];
    vis[u] = 1;
    int ans = 0;
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        ans = max(ans, 1+f(v));
    }
    return dp[u] = ans;
}
int main(){
    //freopen("ip.txt", "r", stdin);
    int n, e; cin>>n>>e;
    for(int i = 1; i <= e; i++){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
    }
    int mxLen = 0;
    for(int i = 1; i <= n; i++) mxLen = max(mxLen, f(i));

    cout<<mxLen<<'\n';
}
