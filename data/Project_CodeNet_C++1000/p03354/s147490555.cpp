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
  vector<int> a(n);
  UnionFind uf(n);
  rep(i,n) cin >> a[i];
  rep(i,m) {
    int x,y;
    cin >> x >> y;
    uf.unite(x-1,y-1);
  }
  
  int ans = 0;
  rep(i,n) if(uf.same(i,a[i]-1)) ++ans;
  cout << ans << endl;
}