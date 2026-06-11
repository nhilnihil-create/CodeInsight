#include <bits/stdc++.h>
using namespace std;

using P = pair<int, int>;
long long n, m;
vector<vector<int>> g;
vector<vector<bool>> ch;
queue<P> qu;

long long solve();

int main() {
  cin >> n >> m;
  g.resize(n);
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }
  cout << solve() << endl;
  return 0;
}

long long solve() {
  ch.assign(n, vector<bool>(2, 0));
  ch[0][0] = 1;
  qu.push(P(0, 0));
  while (qu.size()) {
    P now = qu.front();
    qu.pop();
    now.second = !now.second;
    for (auto to : g[now.first]) {
      P nxt = now;
      nxt.first = to;
      if (!ch[to][nxt.second]) {
        ch[to][nxt.second] = 1;
        qu.push(nxt);
      }
    }
  }
  if (ch[0][0] && ch[0][1]) return n * (n - 1) / 2 - m;
  long long cnt[2] = {};
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < 2; ++j) cnt[j] += ch[i][j];
  return cnt[0] * cnt[1] - m;
}