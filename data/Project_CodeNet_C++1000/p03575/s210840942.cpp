#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

#include <bits/stdc++.h>
using namespace std;

class Dis{
  public:
  vector<ll> rank,p,siz;
  
  Dis(int s){
    rank.resize(s,0);
    p.resize(s,0);
    siz.resize(s,1);
    rep(i,s) makeSet(i);
  }
  
  void makeSet(int x){
    p[x]=x;
    rank[x]=0;
  }
  
  bool same(int x,int y){
    return findSet(x)==findSet(y);
  }
  
  void unite(int x,int y){
    if(same(x,y)) return;
    link(findSet(x),findSet(y));
  }
  
  void link(int x,int y){
    if(rank[x]>rank[y]){
      p[y]=x;
      siz[x]+=siz[y];
    }
    else{
      p[x]=y;
      siz[y]+=siz[x];
      if(rank[x]==rank[y]) rank[y]++;
    }
  }
  
  int findSet(int x){
    if(x != p[x]) p[x]=findSet(p[x]);
    return p[x];
  }
  
  ll size(int x){
    return siz[findSet(x)];
  }
};


int main(){
  ll n,m;
  cin>>n>>m;
  
  vector<int> A(m),B(m);
  int a,b;
  rep(i,m){
    cin>>a>>b;
    A[i]=a-1;
    B[i]=b-1;
  }
  
  int ans=0;
  rep(i,m){
    Dis ds=Dis(n);
    
    rep(j,m){
      if(j==i) continue;
      ds.unite(A[j],B[j]);
    }
    if(!ds.same(A[i],B[i])) ans++;
  }
  cout<<ans<<endl;

  return 0;
}