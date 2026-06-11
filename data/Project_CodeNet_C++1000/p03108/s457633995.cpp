#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using P=pair<ll,ll>;
struct Unionfind {
  vector<int> d;
  Unionfind(int n=0): d(n,-1) {}
  int find(int x) {
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
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
  ll n,m;
  cin>>n>>m;
  vector<P> ab(m);
  for(int i=0;i<m;i++){
    ll a,b;
    cin>>a>>b;
    --a;
    --b;
    ab[i].first=a;
    ab[i].second=b;
  }
  ll add[m]={};
  Unionfind uf=Unionfind(n);
  for(int i=m-1;i>=0;i--){
    if(uf.same(ab[i].first,ab[i].second)){
      continue;
    }
    add[i]=ll(uf.size(ab[i].first))*ll(uf.size(ab[i].second));
    uf.unite(ab[i].first,ab[i].second);
  }
ll temp=0;
  for(int i=0;i<m;i++){
    temp+=add[i];
    cout<<temp<<endl;
  }
  return 0;
}
