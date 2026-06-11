#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef pair<int, int> p;
typedef long long ll;

vector<bool> seen;
vector<vector<int>> g;

void dfs(int v) {
  seen[v] = true;
  for (auto next_v : g[v]) {
    if (seen[next_v]) continue;
    dfs(next_v);
  }
}
int main() {
  int n,m;
  cin >> n>>m;
  g.resize(n);
  seen.assign(n, false);
  rep(i, m) {
    int x, y, z;
    cin >> x >> y >> z;
    x--;
    y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int ans = 0;
  rep(i, n) {
    if (seen[i]) continue;
    dfs(i);
    ans++;
  }
  cout << ans << endl;
  return 0;
}