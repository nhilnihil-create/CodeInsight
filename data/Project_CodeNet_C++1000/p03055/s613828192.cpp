#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
using ll = long long;
const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

vector<vector<int>> to;
void dfs(int now, int prev, int dep, int& mx, int& node) {
  if (chmax(mx, dep))
    node = now;
  for (auto next : to[now]) {
    if (next == prev)
      continue;
    dfs(next, now, dep+1, mx, node);
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  if (n == 1) {
    cout << "First\n";
    return 0;
  }
  to.resize(n);
  rep(i, n-1) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    to[a].push_back(b);
    to[b].push_back(a);
  }
  int k = 1, root = 0;
  dfs(0, -1, 1, k, root);
  dfs(root, -1, 1, k, root);
  if (k%3 != 2)
    cout << "First\n";
  else
    cout << "Second\n";
  return 0;
}