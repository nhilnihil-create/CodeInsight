#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int N, M;
  cin >> N >> M;

  vector<vector<int>> G(N);
  vector<int> inE(N, 0);
  rep(i, N + M - 1) {
    int A, B;
    cin >> A >> B;
    A--, B--;
    G[A].emplace_back(B);
    inE[B]++;
  }

  queue<int> que;
  vector<int> dist(N, -1);
  vector<int> answer(N, -1);
  rep(i, N) {
    if (inE[i] == 0) {
      que.emplace(i);
      dist[i] = 0;
      answer[i] = 0;
    }
  }

  while (!que.empty()) {
    int u = que.front();
    que.pop();
    for (auto v : G[u]) {
      inE[v]--;
      if (dist[v] < dist[u] + 1) {
        dist[v] = dist[u] + 1;
        answer[v] = u + 1;
      }
      if (inE[v] == 0) que.emplace(v);
    }
  }

  rep(i, N) cout << answer[i] << endl;
  return 0;
}