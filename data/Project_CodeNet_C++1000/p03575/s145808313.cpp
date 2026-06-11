#include <bits/stdc++.h>
using namespace std;

struct UnionFind{
  vector<int> p;
  UnionFind(int n){
    p.resize(n+1);
    for(int i=0; i<=n; i++)
      p[i] = i;
  }
  int find(int x){
    if(p[x] == x)  return x;
    return p[x] = find(p[x]);
  }
  void unite(int x, int y){
    x = find(x);
    y = find(y);
    if(x == y)  return;
    p[x] = y;
  }
};

int main(){
  int n, m;  cin >> n >> m;
  vector<pair<int, int>> edge(m);

  for(int i=0; i<m; i++)
    cin >> edge[i].first >> edge[i].second;

  long ans = 0;
  for(int i=0; i<m; i++){
    UnionFind uf(n);
    for(int j=0; j<m; j++){
      if(j == i)  continue;
      uf.unite(edge[j].first, edge[j].second);
    }
    bool ok = false;
    for(int i=2; i<=n; i++)
      if(uf.find(1) != uf.find(i)){
	ok = true;
	break;
      }
    if(ok)  ans++;
  }
  
  cout << ans << endl;
  return 0;
}
