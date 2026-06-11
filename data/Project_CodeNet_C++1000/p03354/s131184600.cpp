#include <bits/stdc++.h>
using namespace std;

struct UnionFind{
  vector<long long> par;

  UnionFind(int n){
    par.assign(n,-1);
  }

  void unite(long long x, long long y){
    x=root(x);y=root(y);
    if(x==y) return;

    if(par[x]>par[y]){
      swap(x,y);
    }
    par[x]+=par[y];
    par[y]=x;
  }

  long long root(long long x){
    if(par[x]<0){
      return x;
    }else{
      return par[x]=root(par[x]);
    }
  }

  bool same(long long x, long long y){
    return root(x)==root(y);
  }

  int size(long long x){
    return -par[root(x)];
  }

};

int main(){
  long long n,m,ans=0;
  cin >> n >> m;
  UnionFind uf(n);
  long long p[n],x[m],y[m];
  for(int i=0;i<n;i++){
    cin >> p[i];
    p[i]--;
  }
  for(int i=0;i<m;i++){
    cin >> x[i] >> y[i];
    x[i]--;y[i]--;
    uf.unite(x[i],y[i]);
  }
  for(int i=0;i<n;i++){
    if(uf.same(i,p[i])){
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}