#include<bits/stdc++.h>
using namespace std;
using Int = long long;

//INSERT ABOVE HERE
signed main(){
  Int n;
  cin>>n;
  vector<Int> d(n);
  for(Int i=0;i<n;i++) cin>>d[i];
  map<Int, Int> r;
  for(Int i=0;i<n;i++) r[d[i]]=i;

  vector<vector<Int> > G(n);
  auto NO=[](){cout<<-1<<endl;exit(0);};
  auto add_edge=[&](Int x,Int y){
		  G[x].emplace_back(y);
		  G[y].emplace_back(x);
		};

  using P = pair<Int, Int>;
  priority_queue<P> pq;
  vector<Int> s(n,1),used(n,0);
  for(Int i=0;i<n;i++) pq.emplace(d[i],i);
  
  while(pq.size()>1u){
    Int x,v;
    tie(x,v)=pq.top();pq.pop();
    
    Int nd=x-(n-s[v])+s[v];
    if(!r.count(nd)) NO();
    
    Int u=r[nd];    
    if(used[u]) NO();
    
    add_edge(v,u);
    s[u]+=s[v];    
    used[v]=1;
  }

  vector<Int> sz(n,1),dp(n,0);
  function<Int(Int, Int)> dfs=
    [&](Int v,Int p){
      for(Int u:G[v]){
	if(u==p) continue;
	dp[v]+=dfs(u,v);
	dp[v]+=sz[u];
	sz[v]+=sz[u];
      }
      return dp[v];
    };
  
  if(d[0]!=dfs(0,-1)) NO();
  
  for(Int v=0;v<n;v++)
    for(Int u:G[v]) if(v<u) cout<<v+1<<" "<<u+1<<endl;
  return 0;
}
