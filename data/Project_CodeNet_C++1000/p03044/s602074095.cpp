#include<bits/stdc++.h>
using namespace std;

using P=pair<int,int>;
vector<int> res;
vector<vector<P>> g;

void dfs(int v,int p,int c){
  res[v]=c;
  for(auto nv : g[v]){
    if(nv.first==p) continue;
    if(nv.second & 1) dfs(nv.first,v,1-c);
    else dfs(nv.first,v,c);
  }
}

int main(){
  int n;
  cin >> n;
  g.assign(n,vector<P>());
  for(int i=0;i<n-1;++i){
    int u,v,w;
    cin >> u >> v >> w;
    u--;
    v--;
    g[u].push_back(P(v,w));
    g[v].push_back(P(u,w));
  }
  res.assign(n,0);
  dfs(0,-1,1);
  for(auto v : res) cout << v << endl;
  return 0;
}
