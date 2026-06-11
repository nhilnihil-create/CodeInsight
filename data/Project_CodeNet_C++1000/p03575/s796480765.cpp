#include <bits/stdc++.h>
//#include "atcoder/all"
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
const ll mod = 1e9 + 7;

vector<bool> flag;

void dfs(const vector<vector<int>>& G, int now) {
  if (flag[now]) return;
  flag[now] = true;

  for (int nv : G[now]) {
    if (flag[nv] == false) {
      dfs(G, nv);
    }
  }

  return;
}
int main() {
  int n, m;
  cin >> n >> m;

  vector<pair<int, int>> coord(m);

  for (int i = 0; i < m; i++) {
    cin >> coord[i].first >> coord[i].second;
    coord[i].first--;
    coord[i].second--;
  }

  int ans = 0;

  for (int i = 0; i < m; i++) {
    vector<vector<int>> G(n);
    for (int j = 0; j < m; j++) {
      if (i == j) {
        continue;
      } else {
        G[coord[j].first].push_back(coord[j].second);
        G[coord[j].second].push_back(coord[j].first);
      }
    }

    flag.assign(n, false);
    dfs(G, 0);

    auto it = find(flag.begin(), flag.end(), false);

    if (it != flag.end()) {  // falseがあるなら、橋
      ans++;
      // cout << coord[i].first + 1 << "  " << coord[i].second + 1 << endl;
    }
  }

  cout << ans << endl;
}
