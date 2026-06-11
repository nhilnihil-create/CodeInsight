#include <bits/stdc++.h> 
using namespace std; 
typedef long long ll;
const int mxN=1e9;
const ll mod = 1e9+7;

int dp[100000];
int n,m;
vector<int> adj[100000];
bool vis[100000];
int ans = 0;

int dfs(int a){
    
    if(vis[a]) return dp[a];
    vis[a]=1;
    if(adj[a].size()==0){
        dp[a]=0;
        return 0;
    }

    int d = 0;

    for(int i=0;i<adj[a].size();i++){
        d = max(d,dfs(adj[a][i]));
    }

    dp[a]=d+1;
    return dp[a];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    cin>>n>>m;

    memset(dp,0,sizeof(dp));

    for(int i=0;i<n;i++) adj[i].clear();

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
    }

    for(int i=0;i<n;i++){
        if(!vis[i])ans=max(ans,dfs(i));
    }

    cout<<ans;
}