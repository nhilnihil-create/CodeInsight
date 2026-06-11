#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, u, v, w;
  cin >> n;
  vector<vector<P>> g(n);
  rep(i, n - 1) {
    cin >> u >> v >> w;
    u--, v--;
    g[u].emplace_back(v, w);
    g[v].emplace_back(u, w);
  }

  vector<int> ans(n, -1);
  ans[0] = 0;
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int a = q.front();
    q.pop();
    for (auto x : g[a]) {
      int b = x.first, c = x.second;
      if (ans[b] != -1) continue;
      ans[b] = (ans[a] + c) % 2;
      q.push(b);
    }
  }

  rep(i, n) cout << ans[i] << endl;

  return 0;
}
