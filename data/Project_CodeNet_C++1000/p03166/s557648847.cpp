#include <bits/stdc++.h>
using namespace std ;

int dp[100000] = {} ;
vector<vector<int>> adj(100000) ;

int longest(int v) {

  if(dp[v]!=-1) return dp[v] ;
  
  if(adj[v].size()==0) {
  	dp[v] = 0 ;
  }
  
  else {

    for(int i : adj[v]) {    	
      dp[v] = max(dp[v],1 + longest(i)) ;
    }
  }
  
  return dp[v] ;
} 


int main() {

  int n,m; cin>>n>>m;
  
  for(int i=0; i<m; i++) {
    int x,y; cin>>x>>y ;
    adj[x-1].push_back(y-1) ;
  }
  
  for(int i=0; i<n; i++) dp[i] = -1 ;
  
  int ans = 0 ;
  
  for(int i=0; i<n; i++){
    ans = max(ans, longest(i)) ;
  }
  
  cout<<ans ;
  
  return 0 ;
} 

