#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int H, W, D, Q;
int A[301][301];
int dp[300 * 300 + 1];
int L[100000], R[100000];

int main(int argc, char* argv[]) {
  cin >> H >> W >> D;

  unordered_map<int, pair<int, int>> map;
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      cin >> A[i][j];
      map[A[i][j]] = make_pair(i, j);
    }
  }
  cin >> Q;
  for (int i = 0; i < Q; i++)
    cin >> L[i] >> R[i];

  for (int i = 1; i <= H * W; i++) {
    if (i <= D) {
      dp[i] = 0;
    } else {
      auto prev = map[i - D];
      auto present = map[i];
      dp[i] = dp[i - D] + abs(present.first - prev.first) +
              abs(present.second - prev.second);
    }
  }

  for (int i = 0; i < Q; i++)
    cout << dp[R[i]] - dp[L[i]] << endl;

  return 0;
}