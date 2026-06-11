#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
bool dp[8050][32005] = {};
bool can(vector<int> in, int target) {
  memset(dp, false, sizeof(dp));
  dp[0][16000] = true;
  int n = (int) in.size();
  for (int i = 0; i < n; i++) {
    int x = in[i];
    for (int j = 0; j < 32001; j++) {
      if (j - x >= 0) dp[i + 1][j - x] |= dp[i][j];
      if (j + x < 32001) dp[i + 1][j + x] |= dp[i][j];
    }
  }
  return dp[n][16000 + target];
}
signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  string in;
  cin >> in;
  int x, y;
  cin >> x >> y;
  if (in.back() == 'F') in += 'T';
  int pre = -1, it = 0;
  vector<vector<int>> v(2);
  for (int i = 0; i < (int) in.size(); i++) {
    if (in[i] == 'T') {
      v[it++ % 2].push_back(i - pre - 1);
      pre = i;
    }
  }
  x -= v[0][0];
  if (can(vector<int>(v[0].begin() + 1, v[0].end()), x) && can(v[1], y)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;	
}