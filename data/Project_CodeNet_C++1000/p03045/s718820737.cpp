#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

struct UnionFind{
  vector<int> d;
  UnionFind(int n) : d(n, -1){}
  int find(int x){
    if(d.at(x) < 0) return x;
    return d.at(x) = find(d.at(x));
  }
  bool unite(int x, int y){
    x = find(x); y = find(y);
    if(x == y) return false;
    if(d.at(x) > d.at(y)) swap(x, y);
    d.at(x) += d.at(y);
    d.at(y)= x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return -d.at(find(x)); }
};

int main(){
  int n, m;
  cin >> n >> m;
  UnionFind uf(n);
  rep(i, m){
    int x, y, z;
    cin >> x >> y >> z;
    x--; y--;
    uf.unite(x, y);
  }
  int ans = 0;
  rep(i, n){
    if(uf.d.at(i) < 0) ans++;
  }
  cout << ans << endl;
  return 0;
}