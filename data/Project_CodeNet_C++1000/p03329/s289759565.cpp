#include <bits/stdc++.h>
using namespace std;
int main()
  {int N; cin >> N;
  vector<int> dp(N + 1, 1e7); dp[0] = 0;
  for (int i = 0; i < N; ++i)
    {for (auto j : {6, 9})
      {for (auto k = 1; i + k <= N; k *= j) dp[i + k] = min(dp[i + k], dp[i] + 1);}}
  cout << dp[N] << endl;}