#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using ll = long long;

struct UnionFind
{
  vi p,r;
  UnionFind(int n){
    p.resize(n, -1);
    r.resize(n,1);
  }
  int find(int x){
    if(p[x] == -1)return x;
    else return p[x] = find(p[x]);
  }
  void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(r[x] > r[y]){
      swap(x,y);
    }
    if(r[x] == r[y]){
      r[y]++;
    }
    p[x] = y;
  }
};



int main(){
  int n, m, x, y, cnt=0;
  cin >> n >> m;

  UnionFind uf(n+1);
  vi p(n+1);
  for(int i=1; i<=n; i++){
    cin >> p[i];
  }
  for(int i=0; i<m; i++){
    cin >> x >> y;
    uf.unite(x,y);
  }
  for(int i=1; i<=n; i++){
    if(uf.find(p[i]) == uf.find(i)){
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}