  #include <bits/stdc++.h>
  using namespace std;
  const long mxN =1e5+2 ;
  signed main() {
    int n,m;
    cin >> n>> m ;
    vector<vector<int>>adj(n+1) ;
    for(int i=0,a,b;i<m;i++)
      cin >> a >> b,adj[a].push_back(b);
    // for(auto x:adj){
    //   for(auto y:x)
    //     cout << y  << " " ;
    //   cout << endl ;
    // }
    vector<int>dp(n+1) ;int ans=-1 ;
    function<int(int)> dfs=[&](int v){
      if(!dp[v]){
        dp[v]=0;
        for(int x:adj[v])
          dp[v]=max(dp[v],dfs(x));
        dp[v]++ ;
        ans=max(ans,dp[v]) ;
      } return dp[v] ;
    };
    for(int i=1;i<=n;i++)
      ans=max(ans,dfs(i));
    cout << ans-1 ;
  }