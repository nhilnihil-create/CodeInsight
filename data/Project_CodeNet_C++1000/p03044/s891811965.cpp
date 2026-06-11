#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i=0; i<(n);++i)
const int INF =1001001001;
using ll=long long;
using Edge = pair<ll,ll>;
using Graph =vector<vector<Edge>>;
vector<int> color;
Graph G;
ll N;
void dfs(ll v,ll o=-1){
for(auto u:G[v]){
  if(u.first==o)continue;
  if(u.second%2==0)color[u.first]=color[v];
  else color[u.first]=1-color[v];
  dfs(u.first,v);
}
}
int main() {
cin>>N;
G.resize(N);
rep(i,N-1){
  ll a,d,c;
  cin>>a>>d>>c;
  --a;
  --d;
  G[a].push_back(Edge(d,c));
  G[d].push_back(Edge(a,c));
}
color.resize(N,-1);
color[0]=0;
dfs(0);
rep(i,N)cout<<color[i]<<endl;
return 0;
}
