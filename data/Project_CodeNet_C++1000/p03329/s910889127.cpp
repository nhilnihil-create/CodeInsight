#include <bits/stdc++.h>
using namespace std;
const int INF = 100005;
void chmin(int &a, int b)
{
  a = min(a, b);
}
int main()
{
  int n;
  cin >> n;
  vector<int> dp(n + 1, INF);
  dp[0] = 0;
  int m6, m9;
  m6 = m9 = 1;
  for(int i = 1; i <= n; ++i) {
    chmin(dp[i], dp[i - 1] + 1);
    if (m6*6 <= i) m6 *= 6;
    if (m9*9 <= i) m9 *= 9;
    chmin(dp[i], dp[i - m6] + 1);
    chmin(dp[i], dp[i - m9] + 1);
  }
  cout << dp.back() << endl;
  return 0;
}