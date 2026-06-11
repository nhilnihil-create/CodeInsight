#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
int main(void) {
  int n;
  cin >> n;
  vector<int> dp(n + 1, -1);
  queue<int> q;
  dp[0] = 0;
  q.push(0);
  while(!q.empty()) {
    int temp = q.front();
    q.pop();
    if (temp + 1 <= n && dp[temp + 1] < 0) {
      dp[temp + 1] = dp[temp] + 1;
      q.push(temp + 1);
    }
    for (int i = 6; temp + i <= n; i *= 6) {
      if (dp[temp + i] < 0) {
        dp[temp + i] = dp[temp] + 1;
        q.push(temp + i);
      }
    }
    for (int i = 9; temp + i <= n; i *= 9) {
      if (dp[temp + i] < 0) {
        dp[temp + i] = dp[temp] + 1;
        q.push(temp + i);
      }
    }
  }
  cout << dp[n] << endl;
  return 0;
}