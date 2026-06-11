#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;
struct UnionFind {
  vector<int> parent,s;
  UnionFind(int n): parent(n), s(n){
    rep(i,n) {
      parent[i] = i;
      s[i] = 1;
    }
  }
  int root(int x) { return parent[x]==x ? x : parent[x] = root(parent[x]); }
  bool same(int x, int y) { return root(x)==root(y); }
  int size(int x){ return s[root(x)]; }
  void unite(int x, int y) {
    x = root(x); y = root(y);
    if (x == y) return;
    if (s[x] < s[y]) {
      parent[x] = y;
      s[y] += s[x];
    } else {
      parent[y] = x;
      s[x] += s[y];
    }   
  }
};

int main() {
  int n,m;
  cin >> n >> m;
  vector<int> a(m),b(m);
  rep(i,m) cin >> a[i] >> b[i];
  rep(i,m) --a[i], --b[i];
  
  int ans = 0;
  rep(i,m){
    UnionFind u(n);
    rep(j,m) if(i!=j) u.unite(a[j],b[j]);
    if(!u.same(a[i],b[i])) ++ans;
  }
  cout << ans << endl;
}
