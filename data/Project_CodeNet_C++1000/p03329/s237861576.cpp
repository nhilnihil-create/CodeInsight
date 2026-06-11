#include <bits/stdc++.h>
using namespace std;
int main()
  {int N; cin >> N;
  vector<int> dp(N + 1, 1e7); dp[0] = 0;
  for (int i = 0; i < N; ++i)
    {dp[i + 1] = min(dp[i + 1], dp[i] + 1);
    for (auto k : {6, 9}) for (int p = k; i + p <= N; p *= k) dp[i + p] = min(dp[i + p], dp[i] + 1);}
  cout << dp[N] << endl;}