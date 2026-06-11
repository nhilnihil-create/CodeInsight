#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  vector<int> cnt(N, 0);
  vector<vector<int>> graph(N);
  for (int i = 0; i < N + M - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    graph[a].emplace_back(b);
    cnt[b]++;
  }

  queue<int> que;
  vector<int> parent(N, -1);
  for (int i = 0; i < N; i++) {
    if (cnt[i] == 0) {
      que.push(i);
      parent[i] = 0;
    }
  }

  while (!que.empty()) {
    int u = que.front();
    que.pop();

    for (int v : graph[u]) {
      if (cnt[v] > 1) {
        cnt[v]--;
        continue;
      }

      parent[v] = u + 1;
      que.push(v);
    }
  }

  for (int i = 0; i < N; i++) {
    cout << parent[i] << '\n';
  }
  return 0;
}
