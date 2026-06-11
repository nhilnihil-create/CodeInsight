#include <bits/stdc++.h>
using namespace std;

struct UnionFind{
  vector<long> p;
  vector<long> w;
  UnionFind(long n){
    p.resize(n+1);
    w.resize(n+1, 1);
    for(long i=1; i<=n; i++)  p[i] = i;
  }
  long find(long x){
    if(p[x] == x)  return x;
    return p[x] = find(p[x]);
  }
  void unite(long x, long y){
    x = find(x);
    y = find(y);
    if(x == y)  return;
    p[x] = y;
    w[x] += w[y];
    w[y] = w[x];
  }
  long weight(long x){
    return w[find(x)];
  }
};

int main(){
  long n, m;  cin >> n >> m;
  UnionFind uf(n);

  vector<pair<long, long>> bri(m);
  for(long i=0; i<m; i++)  cin >> bri[i].first >> bri[i].second;
  
  long ma = n * (n-1) / 2;
  vector<long> ans(m, 0);
  ans[m-1] = ma;
  
  for(long i=m-2; i>=0; i--){
    if(uf.find(bri[i+1].first) == uf.find(bri[i+1].second)){
      ans[i] = ans[i+1];
      continue;
    }
    ans[i] = ans[i+1] - uf.weight(bri[i+1].first) * uf.weight(bri[i+1].second);
    uf.unite(bri[i+1].first, bri[i+1].second);
  }
  
  for(auto ai : ans)
    cout << ai << endl;

  return 0;
}
