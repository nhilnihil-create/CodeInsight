#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())

using namespace std;
using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline void dump(vector<T> v) { for (auto& x : v) cerr << x << " "; cerr << endl; }
template<class T> inline void dump(vector<pair<T, T>> v) { for (auto& p : v) cerr << p.first << " " << p.second << endl; }
template<class T> inline void dump(vector<vector<T>> vv) { for (auto& v : vv) {for (auto& x : v) cerr << x << " "; cerr << endl;} }

constexpr int INF = 1e9 + 5;
constexpr long long INFLL = 1LL << 62;
constexpr double eps = (1e-9);

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> children(n+1);   // i 番目の親から繋がっている子 or 子孫
  vector<set<int>> parents(n+1);    // i 番目のノードの親たち
  set<int> nodes;
  for (int i = 1; i <= n; i++) nodes.insert(i);

  rep(i, n - 1 + m) {
    int a, b;
    cin >> a >> b;
    children[a].push_back(b);
    parents[b].insert(a);
    nodes.erase(b);
  }

  int root = *nodes.begin();

  vector<int> ans(n+1, -1);
  ans[root] = 0;

  queue<int> q;
  q.push(root);

  while (!q.empty()) {
    int p = q.front(); q.pop();
    for (auto& child : children[p]) {
      if (parents[child].size() == 1) {
        ans[child] = p;
        q.push(child);
      } else {
        parents[child].erase(p);  // 親が複数いる場合は，後から出てくる方に譲る
      }
    }
  }

  for (int i = 1; i <= n; i++) cout << ans[i] << endl;

  return 0;
}
