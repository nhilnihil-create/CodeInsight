#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,m;
const int mx=1000009;
vector<ll>edg[mx];
int visited[mx];
ll dp[mx];
void dfs(int node){
    visited[node]=1;
    for(auto i:edg[node]){
        if(!visited[i]){
            dfs(i);
         
        }   dp[node]=max(dp[node],dp[i]+1);
    }
}
int main() {
  cin>>n>>m;ll x,y;
  for(int i=0;i<m;i++){
      
      cin>>x>>y;
      edg[x].push_back(y);
  }
    for(int i=1;i<=n;i++){
        
      if(!visited[i]){
          dfs(i);
      }
  }ll ans=0;
      for(int i=1;i<=n;i++){
        
     ans=max(ans,dp[i]);
  }
  cout<<ans;
    
}