#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define ALL(c) (c).begin(), (c).end()
#define SUM(x) std::accumulate(ALL(x), 0LL)
#define MIN(v) *std::min_element(v.begin(), v.end())
#define MAX(v) *std::max_element(v.begin(), v.end())
#define EXIST(v, x) (std::find(v.begin(), v.end(), x) != v.end())

using namespace std;
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
const int INF = 1001001001;
const long long INFL = (1LL<<60);
const double eps = (1e-9);

int main(int argc, char* argv[])
{
  int n;
  cin >> n;
  vector<vector<int>> tree(n, vector<int>());
  vector<pair<int, int>> edges(n-1);
  rep(i, n-1) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    tree[a].push_back(b);
    tree[b].push_back(a);
    edges[i] = make_pair(a, b);
  }

  vector<int> c(n);
  rep(i, n) {
    cin >> c[i];
  }
  sort(ALL(c));

  vector<int> nodes(n, -1);
  queue<int> que;

  nodes[0] = c.back(); c.pop_back();
  que.push(0);

  while (!que.empty()) {
    int v = que.front(); que.pop();
    for (int nv : tree[v]) {
      if (nodes[nv] != -1) continue;
      nodes[nv] = c.back(); c.pop_back();
      que.push(nv);
    }
  }

  int ans = 0;
  rep(i, n-1) {
    auto p = edges[i];
    ans += min(nodes[p.first], nodes[p.second]);
  }

  cout << ans << endl;

  rep(i, n) {
    cout << nodes[i] << " ";
  }
  cout << endl;

  return 0;
}
