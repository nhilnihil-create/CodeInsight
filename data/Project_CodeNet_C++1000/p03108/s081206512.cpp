#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
using ll=long long;

struct UnionFind{
  vector<ll> p;
  vector<ll> s;
  UnionFind(ll n):p(n),s(n,1){
    REP(i,n) p[i]=i;
  }
  ll find(int x){
    if(x==p[x]) return x;
    return p[x]=find(p[x]);
  }
  void unite(int x, int y){
    x=find(x);
    y=find(y);
    if(x==y) return;
    if(s[x]<s[y]) swap(x,y);
    p[y]=x;
    s[x]+=s[y];
  }
  bool same(int x,int y){
    return find(x)==find(y);
  }
  ll size(ll x){
    return s[find(x)];
  }
};

int main(){
  ll N,M; scanf("%lld%lld",&N,&M);
  
  vector es(M,vector<int>(2));
  REP(i,M) {
    scanf("%d%d",&es[i][0],&es[i][1]);
    es[i][0]--,es[i][1]--;
  }
  
  UnionFind t(N);
  ll ans[M+1]{};
  ans[0]=N*(N-1)/2;
  REP(i,M) {
    auto e=es.back();
    es.pop_back();
    if(t.same(e[0],e[1])){
      ans[i+1]=ans[i];
    }else{
      ans[i+1]=ans[i]-t.size(e[0])*t.size(e[1]);
      t.unite(e[0],e[1]);
    }
  }
  REP(i,M) {
    printf("%lld\n",ans[M-i-1]);
  }
}