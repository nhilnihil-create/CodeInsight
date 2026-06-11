#include <algorithm>
#include <cmath>
#include <cstdio>
#include <deque>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

typedef long long ll;

#define MOD 1000000007

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> h(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }
  vector<int> dp(n + k + 10, 1e9 + 10);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 1; j <= k; ++j) {
      dp[i + j] = min(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
    }
  }
  cout << dp[n - 1] << endl;
  return 0;
}