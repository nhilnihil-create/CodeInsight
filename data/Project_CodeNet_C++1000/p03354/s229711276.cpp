#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;
int si[8] = {-1,0,1,-1,1,-1,0,1};
int sj[8] = {-1,-1,-1,0,0,1,1,1};

struct UnionFind {
  vector<int> d;
  // 子は親のIDを，根は木のサイズ*-1を持つ
  UnionFind(int n = 0): d(n,-1){}
  // rootを探索する
  int find(int x){
    if(d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  // 集合を統合する
  bool unite(int x, int y){
    x = find(x); y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x,y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  // 同じ集合に属しているか判定
  bool same(int x, int y) {return find(x) == find(y);}
  // xの属している集合のサイズを返す
  int size(int x) {return -d[find(x)];}
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> p(n);
  rep(i,n) {
    cin >> p[i];
    p[i]--;
  }
  UnionFind uf(n);
  rep(i,m){
    int x, y;
    cin >> x >> y;
    x--; y--;
    uf.unite(x, y);
  }

  int ans = 0;
  rep(i,n){
    if(p[i] == i) {
      ans++;
      continue;
    }
    if(uf.same(p[i], i)) ans++;
  }
  cout << ans << endl;

  return 0;
}
