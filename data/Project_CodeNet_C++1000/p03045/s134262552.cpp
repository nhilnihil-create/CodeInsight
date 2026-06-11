#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
const int INF = 1000000007;

struct UnionFind {
  vector<int> par;  // par[i]:iの親の番号　

  UnionFind(int N) : par(N) {  //最初は全てが根であるとして初期化
    for (int i = 0; i < N; i++) par[i] = i;
  }

  int root(int x) {  // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
    if (par[x] == x) return x;
    return par[x] = root(par[x]);
  }

  void unite(int x, int y) {  // xとyの木を併合
    int rx = root(x);         // xの根をrx
    int ry = root(y);         // yの根をry
    if (rx == ry) return;  // xとyの根が同じ(=同じ木にある)時はそのまま
    par[rx] =
        ry;  // xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
  }

  bool same(int x, int y) {  // 2つのデータx, yが属する木が同じならtrueを返す
    int rx = root(x);
    int ry = root(y);
    return rx == ry;
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  UnionFind tree(n);
  rep(i, m) {
    int x, y, z;
    cin >> x >> y >> z;
    --x, --y;
    tree.unite(x, y);
  }
  vector<bool> e(n);
  int cnt = 0;
  rep(i, n) {
    int r = tree.root(i);
    if (e[tree.root(i)] == false) {
      e[tree.root(i)] = true;
      cnt++;
    }
  }
  cout << cnt << endl;
}
