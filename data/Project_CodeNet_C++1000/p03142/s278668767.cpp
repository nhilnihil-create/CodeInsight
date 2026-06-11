#include<bits/stdc++.h>
using namespace std;
#define int long long

#ifdef LOCAL_DEBUG
  #include "LOCAL_DEBUG.hpp"
#endif

vector<int> tsort(vector<vector<int>> G){

  int n = G.size();
  vector<int> sorted,indeg(n,0); //入次数
  for(int u = 0; u < n; u++){
    for(int v : G[u]){
      indeg[v]++;
    }
  }

  //priority_queue<int,vector<int>,greater<int>> q; //最小値
  queue<int> q;
  for(int u = 0; u < n; u++){
    if(indeg[u] == 0) q.push(u);
  }
  while(!q.empty()){
    int u = q.front(); q.pop();
    for(int v : G[u]){
      indeg[v]--;
      if(indeg[v] == 0) q.push(v);
    }
    sorted.push_back(u);
  }
  return sorted;
}

signed main(){

  int n,m; cin >> n >> m;
  vector<vector<int>> G(n);
  for(int i = 0; i < n-1+m; i++){
    int a,b; cin >> a >> b;
    a--,b--;
    G[a].push_back(b);
  }

  auto v = tsort(G);
  vector<int> dp(n,0),ans(n,0);
  // function< void(int,int,int) > dfs =
  // [&](int u,int pre,int d){
  //   if(dp[u] < d){
  //     dp[u] = d;
  //     ans[u] = pre+1 - (pre == -1);
  //   }
  //   for(int v : G[u]){
  //     if(v == pre) continue;
  //     dfs(v,u,d+1);
  //   }
  //
  // };
  // dfs(v[0],-1,0);

  for(int i = 0; i < n; i++){
    for(int u : G[v[i]]){
      if(dp[u] < dp[v[i]]+1){
        dp[u] = dp[v[i]]+1;
        ans[u] = v[i]+1;
      }
    }
  }

  for(int i = 0; i < n; i++){
    cout << ans[i] << endl;
  }

  return 0;
}
