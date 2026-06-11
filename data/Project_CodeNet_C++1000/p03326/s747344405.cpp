#include <bits/stdc++.h>
using namespace std;
int64_t DP[1010][1010][8]; // i番目までに、j個選んだ時、8パターンの最大値

int main()
{
  int64_t N, M, ans = 0;
  cin >> N >> M;
  vector<vector<int64_t>> A(N, vector<int64_t>(3));
  for (int i = 0; i < N; i++)
    cin >> A.at(i).at(0) >> A.at(i).at(1) >> A.at(i).at(2);
  for (int64_t i = 1; i <= N; i++)
  {
    for (int64_t j = 0; j <= min(M, i); j++)
    {
      int64_t a = -(1LL << 62), b = -(1LL << 62);
      for (int k = 0; k < 8; k++)
      {
        if (j <= i - 1)
        {
          a = DP[i - 1][j][k]; // 選ばない場合
        }
        if (j >= 1)
        {
          b = DP[i - 1][j - 1][k];
          for (int n = 0; n < 3; n++)
          {
            if (k & (1 << n))
              b += A.at(i - 1).at(n);
            else
              b -= A.at(i - 1).at(n);
          }
        }
        DP[i][j][k] = max(a, b);
      }
    }
  }
  for (int k = 0; k < 8; k++)
  {
    ans = max(ans, DP[N][M][k]);
  }
  cout << ans << endl;
}
