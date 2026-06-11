#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef tuple<int,int,int> TP;
constexpr int INF = 2e9;
struct UnionFind{
  vector<int> data;
  int __size;
  UnionFind(int sz) {
  data.assign(sz, -1);
  __size = sz;
  }
 
  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);//親は負でサイズを保存
    __size--;
    data[x] += data[y];
    data[y] = x;
    return (true);
  }
 
  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  bool same(int x, int y){
    return find(x) == find(y);
  }
 
  int size(int k) {
    return (-data[find(k)]);
  }

  int union_count() {
    return (__size);
  }
};
int main() {
  int n, m;
  cin >> n >> m;
  UnionFind uf(n);
  rep(i,m) {
    int x, y, z;
    cin >> x >> y >> z;
    x--; y--;
    uf.unite(x, y);
  }
  cout << uf.union_count() << endl;
  return 0;
} 