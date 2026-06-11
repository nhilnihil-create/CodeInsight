#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void solve() {
  int N, M;
  cin >> N >> M;

  vector<vector<int>> V(N+1);
  vector<int> income(N+1);
  vector<int> parent(N+1);


  for (int i = 0; i < N-1+M; i++) {
    int a, b; cin >> a >> b;
    V[a].push_back(b);
    income[b]++;
  }

  int root = 1;
  while (income[root] > 0) {
    root++;
  }

  parent[root] = 0;

  queue<int> q;
  q.push(root);

  while (!q.empty()) {
    int x = q.front(); q.pop();

    for (int dist : V[x]) {
      income[dist]--;
      if (income[dist] == 0) {
        q.push(dist);
        parent[dist] = x;
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    cout << parent[i] << endl;
  }
}

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
  return 0;
}
