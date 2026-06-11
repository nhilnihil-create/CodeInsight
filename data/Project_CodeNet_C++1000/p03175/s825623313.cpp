#include<bits/stdc++.h>
using namespace std;
#define lli long long int
const int MAX = 1e5 + 10;
const int MOD = 1e9 + 7;
lli dp[MAX][2];
int n;
vector<int>adj[MAX];
lli solve(int v, int c, int p){
  if(dp[v][c]!=-1)
    return dp[v][c];
  lli t=1;
  for(auto it=adj[v].begin();it!=adj[v].end();it++){
      if(*it==p) continue;
    if(c==0)
    t=t*(solve(*it,0,v)+solve(*it,1,v))%MOD;
    else t=t*(solve(*it,0,v))%MOD;
  }
  return dp[v][c]=t;
}
int main(){
  memset(dp,-1,sizeof(dp));
  cin>>n;
  for(int i=1;i<n;i++){
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  lli ans=(solve(1,0,-1)+solve(1,1,-1))%MOD;
  cout<<ans<<"\n";
  return 0;
}