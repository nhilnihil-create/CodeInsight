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
  int n;
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }
  vector<int> dp(n + 10, 1e9 + 10);
  dp[0] = 0;
  for (int i = 0; i < n; ++i) {
    dp[i + 1] = min(dp[i + 1], dp[i] + abs(h[i] - h[i + 1]));
    dp[i + 2] = min(dp[i + 2], dp[i] + abs(h[i] - h[i + 2]));
  }
  cout << dp[n - 1] << endl;
  return 0;
}