#include <bits/stdc++.h>

using namespace std;
using u64 = std::uint_fast64_t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<vector<int>> G(N);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  int sum = 0;
  vector<int> C(N);
  for (int i = 0; i < N; i++) {
    cin >> C[i];
    sum += C[i];
  }
  sort(C.begin(), C.end(), greater<int>());
  sum -= C[0];

  vector<int> D(N, -1);
  queue<int> que;
  que.push(0);

  int p = 0;
  D[0] = C[p++];
  while (!que.empty()) {
    int u = que.front();
    que.pop();

    for (int v : G[u]) {
      if (D[v] != -1) continue;

      D[v] = C[p++];
      que.push(v);
    }
  }

  cout << sum << '\n';
  for (int i = 0; i < N; i++) {
    cout << D[i] << (i == N - 1 ? '\n' : ' ');
  }
  return 0;
}
