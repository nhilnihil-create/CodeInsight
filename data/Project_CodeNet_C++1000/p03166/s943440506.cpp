#include<bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> &adj,int cur,vector<int> &dp){
    if(adj[cur].size()==0)  dp[cur]=0;
    if(dp[cur]!=-1) return dp[cur];
    int ans=0;
    for(auto c:adj[cur]){
        ans = max(dfs(adj,c,dp),ans);
    }
    dp[cur]=ans+1;
    return dp[cur];
}
int main(){
    int n,m,x,y;
    cin>>n>>m;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<m;i++){
        cin>>x>>y;
        adj[x].push_back(y);
    }
    vector<int> dp(n+1,-1);
    int ans=0;
    for(int i=1;i<=n;i++){
        ans = max(ans,dfs(adj,i,dp));
    }
    cout<<ans<<endl;
}