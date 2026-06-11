#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define mx INT_MAX
#define mn INT_MIN
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define itr set<int> :: iterator
#define map_it map<int,int> :: iterator
const int mod = 1e9+7;

vector<int> adj[100001];
ll dp[100001][2];

void dfs(int v , int par){
  
  dp[v][0] = 1;
  dp[v][1] = 1;
  for(int u = 0; u<adj[v].size(); u++){
      int child = adj[v][u];
      if(child==par)
        continue;

      dfs(child, v);
      dp[v][0] = (dp[v][0]* (dp[child][0] + dp[child][1])%mod)%mod;
      dp[v][1] = (dp[v][1]* dp[child][0])%mod;
  }
   
  return;
}

int main(){

    // ******* START HERE ******
    
    int n;
    cin>>n;
    
    for(int i=0; i<n-1; i++){
      int x,y;
      cin>>x>>y;
      adj[x].pb(y);
      adj[y].pb(x);
    }
    
    dfs(1, -1);
    int res = (dp[1][0] + dp[1][1])%mod;
    cout<<res<<endl;
    // ***** END HERE ***** 
    return 0;
}
