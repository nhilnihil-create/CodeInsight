#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define rrep(i,n) for(int i = (n)-1; i >= 0; i--)
#define rep1(i,n) for(int i = 1; i <= (n); i++)
#define rrep1(i,n) for(int i = (n); i > 0; i--)

#define ll long long
#define pi pair<int, int>
#define pll pair<ll, ll>

#define MOD 1000000007
#define INF 1000000000000000LL

using namespace std;

#define MAXN 100000

vector<vector<int>> g(MAXN);
ll dp[MAXN+1][2];
bool used[MAXN+1];
ll f(int node, int parent){
  if(used[node])return dp[node][0] + dp[node][1];
  used[node]=true;

  ll c0=1, c1=1;
  for(auto to:g[node]){
    if(to==parent)continue;
    c0*=f(to, node);
    c1*=dp[to][0];
    c0 %= MOD;
    c1 %= MOD;
  }
  dp[node][0]=c0;
  dp[node][1]=c1;
  return (c0+c1)%MOD;
}

int main(){
  int n;cin>>n;
  rep(i, n-1){
    int x,y; cin>>x>>y; x--,y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  cout<<f(0, -1)<<endl;

  return 0;
}