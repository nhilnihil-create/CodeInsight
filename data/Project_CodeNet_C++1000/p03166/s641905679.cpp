#include<bits/stdc++.h>
using namespace std;
int n, m;
int dp[100001];


int dfs(int u, vector<vector<int>>&adj){
      if(dp[u]!=-1)return dp[u];

      int ans=0;
      for(auto i: adj[u]){
            ans=max(ans, dfs(i, adj)+1);
      }
      if(ans!=0)return dp[u]=ans;
      dp[u]=0;
      return 0;
}

int main(){
      cin>>n>>m;
      memset(dp, -1, sizeof(dp));
      vector<vector<int>>adj(n);
      for(int i=0; i<m; i++){
            int u,v;
            cin>>u>>v;
            adj[u-1].push_back(v-1);
      }
      int ans=0;
      for(int i=0; i<n; i++)
      ans=max(ans, dfs(i, adj));
      cout<<ans;
}