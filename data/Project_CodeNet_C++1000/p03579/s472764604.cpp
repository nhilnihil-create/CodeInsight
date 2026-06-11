#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

vector<vector<int>> g;
vector<int> col;

bool dfs(int v, int c) {
  col[v] = c;
  for (auto a : g[v]) {
    if (col[a] != -1) {
      if (col[a] == c) return false;
      continue;
    }
    if (!dfs(a, 1 - c)) return false;
  }
  return true;
}

int main() {
  ll n, m;
  cin >> n >> m;
  g.resize(n, vector<int>());
  rep(i, m) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  col.assign(n, -1);
  ll ans = 0;
  if (dfs(0, 0)) {
    ll cnt = 0;
    rep(i, n) if (col[i] == 0) cnt++;
    ans = cnt * (n - cnt) - m;
  }
  else {
    ans = n * (n - 1) / 2 - m;
  }
  cout << ans << endl;
  return 0;
}
