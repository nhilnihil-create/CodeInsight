#include <bits/stdc++.h>
using namespace std;

struct UnionFind{
  vector<int> d;
  UnionFind(int n){
    d.resize(n,-1);
  }
  int find(int x){
    if(d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return;
  }
  int size(int x){return -d[find(x)];}
};

int main(){
  int n, m;
  cin >> n >> m;
  UnionFind uf(n);
  for(int i=0; i<m; ++i){
    int x, y, z;
    cin >> x >> y >> z;
    --x; --y;
    uf.unite(x,y);
  }
  map<int, bool> mp;
  int ans = 0;
  for(int i=0; i<n; ++i){
    if(mp[uf.find(i)]) continue;
    else{
      mp[uf.find(i)] = true;
      ++ans;
    }
  }
  cout << ans << endl;
}