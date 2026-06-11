#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  int H, W, A, ans{};
  cin >> H >> W;

  vector<vector<int>> c(10, vector<int>(10));
  for (int i = 0; i != 10; i++) {
    for (int j = 0; j != 10; j++) {
      cin >> c[i][j];
    }
  }

  vector<int> dist(10, -1);
  priority_queue<int> q;
  dist[1] = 0;
  q.push(1);
  while (!q.empty()) {
    int j = q.top();
    q.pop();
    for (int i = 0; i != 10; ++i) {
      if (i == j) continue;
      if (dist[i] == -1 || dist[i] > dist[j] + c[i][j]) {
        dist[i] = dist[j] + c[i][j];
        q.push(i);
      }
    }
  }
  
  for (int i = 0; i != H * W; i++) {
    cin >> A;
    if (A != -1) ans += dist[A];
  }
  cout << ans << endl;
}
