#include <bits/stdc++.h>
#define rep(i,n) for (ll i = 0; i < n; ++i)
#define sz(x) int(x.size())
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())
#define FORV(i, v) for (auto i = v.begin(); i != v.end(); i++)
using namespace std;

using ll = long long;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const long long INFL = LLONG_MAX / 3;
const double eps = (1e-9);

void dfs(vector<int>& nodes, vector<int>& c, const vector<vector<int>>& g, const int& v) {
  nodes[v] = c.back(); c.pop_back();
  if (c.empty()) return;
  for (auto& next_v : g[v]) {
    if (nodes[next_v] != 0) continue;
    dfs(nodes, c, g, next_v);
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n; cin >> n;
  vector<int> nodes(n, 0);
  vector<pair<int, int>> edges;
  vector<vector<int>> g(n, vector<int>());
  rep(i, n-1) {
    int a, b; cin >> a >> b; a--; b--;
    edges.emplace_back(a, b);
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> c(n);
  rep(i, n) cin >> c[i];
  sort(ALL(c));

  int start = 0;
  int tmp = 0;
  for (int i = 0; i < n; i++) {
    if (g[i].size() > tmp) {
      start = i;
      tmp = g[i].size();
    }
  }

  dfs(nodes, c, g, start);

  ll ans = 0;
  for (auto& edge : edges) {
    ans += min(nodes[edge.first], nodes[edge.second]);
  }

  cout << ans << endl;
  rep(i, n) cout << nodes[i] << " ";
  cout << endl;

  return 0;
}
