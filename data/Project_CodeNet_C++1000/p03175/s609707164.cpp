#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define int long long
#define f(i,l,n) for(int i=l;i<n;i++) 
#define E "\n"
const int M=1e9+7;

int solve()
{

 
  int n;
  cin >> n;

  vector<int> graph[n+1];
  f(i,0,n-1)
  {
    int x,y;
    cin >> x >> y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }


  int dp[n+1][2]={0},visited[n+1]={0};


  function<void(int)> dfs=[&](int node)
  {
    dp[node][0]=dp[node][1]=1;
    visited[node]=1;
    for(auto x:graph[node])
    {
        if(visited[x]==0)
        {
            dfs(x);
            dp[node][1]=(dp[node][1]*dp[x][0])%M;
            dp[node][0]=(dp[node][0]*(dp[x][0]+dp[x][1])%M)%M;
        }
    }
    //cout<<node<<" "<<dp[node][0]<<" "<<dp[node][1]<<E;
  };

  dfs(1);

  cout<<(dp[1][0]+dp[1][1])%M<<E;

  return 0;  
}


int32_t main()
{

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
     int t = 1;
     //cin >> t;
     while(t--)
     {
          solve();
     }
     return 0;
}