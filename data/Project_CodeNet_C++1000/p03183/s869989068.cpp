#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

struct Block {
  int64 weight;
  int64 strength;
  int64 value;
};

constexpr int S_MAX = 20000;

template<typename T>
vector<vector<T>> Make2DVector(int d1, int d2, T default_value) {
  return vector<vector<T>>(d1, vector<T>(d2, default_value));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<Block> blocks;
  for (int i = 0; i < n; i++) {
    int64 w, s, v;
    cin >> w >> s >> v;
    blocks.push_back(Block({w, s, v}));
  }
  sort(blocks.begin(), blocks.end(), [](const auto& b1, const auto& b2) {
    return (b1.weight + b1.strength) < (b2.weight + b2.strength);
  });

  vector<vector<int64>> dp = Make2DVector<int64>(n + 1, S_MAX + 1, -1);
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= S_MAX; j++) {
      if (dp[i][j] < 0) continue;
      if (i == n - 1) {
        dp[n][0] = max(dp[n][0], dp[n - 1][j]);
        if (j <= blocks[i].strength) {
          dp[n][0] = max(dp[n][0], dp[n - 1][j] + blocks[n - 1].value);
        }
      } else {
        dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        // cout << "i: " << i << " strength: " << blocks[i].strength << endl;
        if (j <= blocks[i].strength && j + blocks[i].weight <= S_MAX) {
          dp[i + 1][j + blocks[i].weight] =
              max(dp[i + 1][j + blocks[i].weight], dp[i][j] + blocks[i].value);
        }
      }
    }
  }
  cout << dp[n][0] << endl;
}
