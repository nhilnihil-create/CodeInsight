#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

vector<vector<P>> G;
int n;
vector<int> ans;

void dfs(int i, int c, int p) {
  ans[i] = c;
  for (auto& e : G[i]) {
    if (e.first == p) {
      continue;
    }
    if (e.second) {
      dfs(e.first, (c ^ 1), i);
    } else {
      dfs(e.first, c, i);
    }
  }
}

int main() {
  cin >> n;
  G.resize(n);
  ans.resize(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    --u;
    --v;
    G[u].push_back(P(v, w % 2));
    G[v].push_back(P(u, w % 2));
  }
  dfs(0, 0, -1);
  for (int i = 0; i < n; i++) {
    cout << ans[i] << endl;
  }
}
