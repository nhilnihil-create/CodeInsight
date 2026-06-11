#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int NIL = -1;
const long long INF = 1LL << 60;
const long long MOD = 1e9+7;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};

int main() {
  int N; cin >> N;
  vector<vector<int>> to(N), cost(N);
  for (int i = 0; i < N-1; ++i) {
    int u, v, w; cin >> u >> v >> w;
    u--; v--;
    to[u].push_back(v);
    to[v].push_back(u);
    cost[u].push_back(w);
    cost[v].push_back(w);
  }
  vector<int> ans(N, -1);
  queue<int> q;
  ans[0] = 0;
  q.push(0);
  while(!q.empty()) {
    int v = q.front();
    q.pop();
    for (int i = 0; i < to[v].size(); ++i) {
      int u = to[v][i];
      int w = cost[v][i];
      if (ans[u] != -1) continue;
      ans[u] = (ans[v] + w) % 2;
      q.push(u);
    }
  }

  for (int i = 0; i < N; ++i) {
    cout << ans[i] << endl;
  }
}
