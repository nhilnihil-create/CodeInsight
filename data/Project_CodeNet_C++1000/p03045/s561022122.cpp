#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

const int N_MAX = 100010;
vector<vector<int>> G(N_MAX, vector<int>(0));
vector<bool> gone(N_MAX);

void dfs(int x) {
  gone[x] = true;
  for (auto g : G[x]) {
    if (gone[g]) continue;
    dfs(g);
  }
  return;
}

int main() {
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < M; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    x--;
    y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (!gone[i]) {
      dfs(i);
      ans++;
    }
  }
  cout << ans << endl;
}