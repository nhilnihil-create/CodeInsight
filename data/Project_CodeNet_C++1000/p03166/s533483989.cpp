#include <bits/stdc++.h>
using namespace std;
vector<int> graph[100001];
int dp[100001];   // dp[i] denotes the longest path starting at node i
int solve(int src){
    if(dp[src]!=-1){
        return dp[src];
    }
   int ans=0; bool f=false;
   for(int child: graph[src]){
       f=true;
       ans= max(ans, solve(child) );
   } 
return dp[src]= f? 1+ans: 0;
}

int32_t main() {
      int n,m;
       memset(dp,-1,sizeof dp);
      cin>>n>>m;
      for(int i=0;i<m;++i){
          int u,v;
          cin>>u>>v;
          graph[u].push_back(v);
      }
      int ans=0;
      //solve(1);
      for(int i=1;i<=n;++i){
          ans=max(ans, solve(i));
      }
    cout<<ans;
    return 0;
}
