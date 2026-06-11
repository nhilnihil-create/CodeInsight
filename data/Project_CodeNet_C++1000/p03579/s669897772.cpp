#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n);++i)
const int INF =1001001001;
using ll=long long;
using Edge = pair<ll,ll>;
using Graph =vector<vector<ll>>;
Graph G;
vector<int> color;
bool dfs(int v,int c=0){
  color[v]=c;
  for(auto p:G[v]){
    if(color[p]!=-1){
      if(color[p]==color[v])return false;
    }else{
      if(!dfs(p,1-c)){
        return false;
      }
    }
  }
  return true;
}
int main() {
  ll n,m;
  cin>>n>>m;
  G.resize(n);
  rep(i,m){
    ll a,b;
    cin>>a>>b;
    a--;b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  color.resize(n,-1);
  if(!dfs(0))cout<<n*(n-1)/2-m<<endl;
  else{
    ll a=0,b=0;
    rep(i,n){
      if(color[i]==0)a++;
      else if(color[i]==1)b++;
      }
      cout<<a*b-m<<endl;
    }
}

