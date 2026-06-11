#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
using namespace std;

using ll = long long;
using P = pair<ll, ll>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void dump(vector<T> v) { for (auto& x : v) cerr << x << " "; cerr << endl; }
template<class T> inline void dump(vector<pair<T, T>> v) { for (auto& p : v) cerr << p.first << " " << p.second << endl; }
template<class T> inline void dump(vector<vector<T>> vv) { for (auto& v : vv) {for (auto& x : v) cerr << x << " "; cerr << endl;} }

constexpr int INF = 1e9+5;
constexpr long long INFLL = 1LL<<60;
constexpr double eps = (1e-9);

class UnionFind {
public:
  // 親の番号を格納する。親だった場合は-(その集合のサイズ)
  vector<int> parent;

  // 作るときは parent の値を全て -1 にする
  // こうすると全てバラバラになる
  UnionFind(const int& n = 0) : parent(n, -1) {}

  // x がどのグループに属しているか調べる
  int find(const int& x) {
    if (parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
  }

  // x と y をくっつける  O(log n)
  bool unite(int x, int y) {
    // x と y を直接くっつけるのではなく，root(x) に root(y) をくっつける
    x = find(x);
    y = find(y);
    if (x == y) return false;  // すでにくっついているからくっつけない

    // 大きい方(x) に小さい方(y)をくっつけたい 大小が逆だったらひっくり返す
    if (size(x) < size(y)) swap(x, y);

    parent[x] += parent[y];  // x のサイズを更新する
    parent[y] = x;  // y の親を x に変更する
    return true;
  }

  // 自分のいるグループの頂点数を調べる
  int size(const int& x) { return -parent[find(x)]; }

  // x と y が同じグループに属しているか否か
  bool same(const int& x, const int& y) { return find(x) == find(y); }
};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  ll n, m;
  cin >> n >> m;

  vector<pair<int, int>> bridges;
  rep(i, m) {
    int a, b; cin >> a >> b; a--; b--;
    bridges.emplace_back(a, b);
  }

  ll ans = (n * (n-1)) / 2;   // 全部の橋が落ちている
  vector<ll> x;
  x.push_back(ans);

  UnionFind uf(n);
  for (auto itr = bridges.rbegin(); itr != bridges.rend(); itr++) {
    int a = itr->first;
    int b = itr->second;
    if (!uf.same(a, b)) {
      ans -= ll(uf.size(a)) * uf.size(b);
    }
    uf.unite(a, b);
    x.push_back(ans);
  }
  x.pop_back();  // 全部の橋が繋がった状態については答えない

  reverse(ALL(x));
  rep(i, x.size()) cout << x[i] << endl;

  return 0;
}
