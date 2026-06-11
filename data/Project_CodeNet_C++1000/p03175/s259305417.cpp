#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e5+10;
const int mod=1e9+7;
const int inf=1e9;

ll dp[N][2];
bool vis[N];
vector<int> g[N];

void dfs(int u){
    if(vis[u]) return;
    vis[u]=true;
    dp[u][0]=1;
    dp[u][1]=1;
    for(auto v : g[u]){
        if(vis[v]) continue;
        dfs(v);
        dp[u][0]=(dp[u][0]*(dp[v][0] + dp[v][1]))%mod;
        dp[u][1]=(dp[u][1]*dp[v][0])%mod;
    }
}

int main(){
    int n;
    cin>>n;
    int a,b;
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1);
    ll ans=(dp[1][0] + dp[1][1])%mod;
    cout<<ans<<'\n';
    return 0;
}
