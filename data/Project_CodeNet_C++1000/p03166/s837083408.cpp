#include <bits/stdc++.h>
using namespace std;
 
void count(int v, bool vis[], int dp[], vector<int> adj[]){
    vis[v]=1;
    for(int i=0; i<adj[v].size(); i++){
        if(!vis[adj[v][i]]) count(adj[v][i],vis,dp, adj);
        dp[v] = max(dp[v], 1+dp[adj[v][i]]);
    }
} 
 
int Lpath(vector<int> adj[], int n){
    bool vis[n]={0};
    int dp[n]={0};
    for(int i=1; i<n; i++){
        if(!vis[i]){
            count(i,vis,dp, adj);
        }
    }
    int ans=0;
    for(int i=0; i<n; i++) ans = max(ans, dp[i]);
    return ans;
}
 
int main(){
  int n,m,x,y;
  cin>>n>>m;
  vector<int> adj[n+1];
  for(int i=0; i<m; i++) {
      cin>>x>>y;
      adj[x].push_back(y);
  }
  cout<<Lpath(adj,n+1);
  return 0;
}