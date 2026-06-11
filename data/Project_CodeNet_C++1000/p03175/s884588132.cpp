#include<bits/stdc++.h>
using namespace std;

#define pb push_back

typedef long long ll;
const int N = 1e5+5;
const ll MOD = 1e9+7;

int n;
ll dp[N][2];
vector<int> adj[N];

void dfs(int u , int p){
  for(auto v : adj[u])
    if(v != p) 
      dfs(v,u) , dp[u][0] = (dp[u][0]*((dp[v][0]+dp[v][1])%MOD))%MOD , dp[u][1] = (dp[u][1]*dp[v][0])%MOD;
}

int main(){

  cin >> n;

  for(int i = 0 ; i < N ; i++)
    for(int j = 0 ; j < 2 ; j++) dp[i][j] = 1;

  for(int i = 1 ; i < n ; i++){
    int x , y;
    cin >> x >> y;
    adj[x].pb(y) , adj[y].pb(x);
  }

  dfs(1,0);

  cout << (dp[1][0] + dp[1][1])%MOD << "\n";

}
