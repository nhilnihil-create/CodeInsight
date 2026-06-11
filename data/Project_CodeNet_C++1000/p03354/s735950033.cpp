#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
struct UnionFind {
  /*
  UnionFind uf(x)で初期化
  root(x) xの根を返す
  unite(x,y) xとyを同一の根にする
  same(x,y) xとyの根が同一ならtrue
  size(x)　集合の大きさを返す*/
  vector<int> d;
  UnionFind(int n) : d(n, -1) {}
  int root(int x) {  // xの根を返す
    if (d[x] < 0) return x;
    return d[x] = root(d[x]);
  }
  bool unite(int x, int y) {
    x = root(x);  // xとyを連結する
    y = root(y);
    if (x == y) return 0;
    if ((d[x] > d[y])) swap(x, y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return root(x) == root(y); }
  int size(int x) { return -d[root(x)]; }
};
int main() {
  int N, M;
  cin >> N >> M;
  vector<int> p(N);
  REP(i, N) cin >> p[i], p[i]--;
  UnionFind uf(N);
  REP(i, M) {
    int a, b;
    cin >> a >> b, a--, b--;
    uf.unite(a, b);
  }
  int ans = 0;
  REP(i, N) {
    if (uf.root(i) == uf.root(p[i])) ans++;
  }
  cout << ans << endl;
}