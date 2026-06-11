#include <climits>
#include <iostream>
#include <vector>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;

int main(void) {
  int H, W;
  cin >> H >> W;

  vector<vector<int>> dist(10, vector<int>(10, INT_MAX));
  rep(i, 10) {
    rep(j, 10) { cin >> dist[i][j]; }
  }
  rep(k, 10) {
    rep(i, 10) {
      rep(j, 10) {
        if (dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  vector<int> A(11, 0);
  rep(i, H) {
    rep(j, W) {
      int a;
      cin >> a;
      A[a + 1]++;
    }
  }
  int answer = 0;
  for (int i = 0; i <= 9; ++i) {
    answer += dist[i][1] * A[i + 1];
  }
  cout << answer << endl;
  return 0;
}
