#include <bits/stdc++.h>
using namespace std;
const int64_t MOD = 1000000007;
int64_t dp[105][100005];

int main()
{
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }
  dp[0][0] = 1;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j <= K; j++)
    {
      (dp[i + 1][j] += dp[i][j]) %= MOD;
      if (j + A.at(i) + 1 <= K)
      {
        dp[i + 1][j + A.at(i) + 1] -= dp[i][j];
        dp[i + 1][j + A.at(i) + 1] += MOD;
        dp[i + 1][j + A.at(i) + 1] %= MOD;
      }
    }
    for (int j = 1; j <= K; j++)
    {
      (dp[i + 1][j] += dp[i + 1][j - 1]) %= MOD;
    }
  }
  cout << dp[N][K] << endl;
}
