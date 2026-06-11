#include <bits/stdc++.h>
#include <random>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rep1(i,n) for (int i = 1; i <= (n); ++i)

using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using ull= unsigned long long;
const ll K_MAX=1e5+5;
const ll Lmax=ll(1e18);
const int Nmax=2e5+1;
const int Nd=61;
const int INF=1e5;

struct UnionFind {
  vector<int> d;
  UnionFind(int n=0): d(n,-1) {}
  int find(int x) {
    if (d[x] < 0) return x; //
    return d[x] = find(d[x]); //
  }
  bool unite(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y);}
  int size(int x) { return -d[find(x)];}
};




int main(){
  int n,m; cin>>n>>m;
  vector<P> ab(m);
  rep(i,m){
    cin>>ab[i].first>>ab[i].second;
    ab[i].first--;
    ab[i].second--;
  }

  UnionFind uf(n);
  vector<ll> ans(m+1);
  ll add=0;
  ans[m]=ll(n)*ll(n-1)/2;

  rep(i,m){
    int a=ab[m-1-i].first;
    int b=ab[m-1-i].second;
    if(uf.same(a,b)){
      add=0;
    }else{
      add=ll(uf.size(a))*ll(uf.size(b));
    }
    ans[m-1-i]=ans[m-i]-add;
    uf.unite(a,b);

  }
  rep(i,m){
    cout<<ans[i+1]<<endl;
  }


}
