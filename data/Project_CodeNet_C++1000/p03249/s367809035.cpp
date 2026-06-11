#include<bits/stdc++.h>
using namespace std;
using Int = long long;

struct UnionFind{
  Int n;
  vector<Int> r,p;
  UnionFind(){}
  UnionFind(Int sz):n(sz),r(sz,1),p(sz,0){iota(p.begin(),p.end(),0);}
  Int find(Int x){
    return (x==p[x]?x:p[x]=find(p[x]));
  }
  bool same(Int x,Int y){
    return find(x)==find(y);
  }
  void unite(Int x,Int y){
    x=find(x);y=find(y);
    if(x==y) return;
    if(r[x]<r[y]) swap(x,y);
    r[x]+=r[y];
    p[y]=x;
  }
};

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

  vector<Int> sz(n,1);
  vector<Int> dp1(n,0),dp2(n,0);
  function<Int(Int, Int)> dfs1=
    [&](Int v,Int p){
      for(Int u:G[v]){
	if(u==p) continue;
	dp1[v]+=dfs1(u,v);
	dp1[v]+=sz[u];
	sz[v]+=sz[u];
      }
      return dp1[v];
    };
  
  function<void(Int, Int, Int)> dfs2=
    [&](Int v,Int p,Int d){
      Int sum=0;
      dp2[v]=dp1[v]+d;
      for(Int u:G[v])
	if(u!=p) sum+=dp1[u]+sz[u];
      for(Int u:G[v])
	if(u!=p) dfs2(u,v,d+sum-(dp1[u]+sz[u])+(n-sz[u]));
    };
  
  dfs1(0,-1);
  dfs2(0,-1,0);

  //for(Int i=0;i<n;i++) cout<<d[i]<<" "<<dp2[i]<<endl;
  for(Int i=0;i<n;i++) if(d[i]!=dp2[i]) NO();
  
  for(Int v=0;v<n;v++)
    for(Int u:G[v]) if(v<u) cout<<v+1<<" "<<u+1<<endl;
  return 0;
}
