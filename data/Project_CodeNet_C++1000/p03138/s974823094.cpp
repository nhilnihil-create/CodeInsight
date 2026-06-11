#include <bits/stdc++.h>
using namespace std;
int64_t DP[100][2]; // i桁目, j: Kに一致する/しない, の時の最大値

int main()
{
  int64_t N, K, a;
  cin >> N >> K;
  vector<int64_t> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
  }
  for (int i = 0; i < 100; i++)
  {
    DP[i][0] = DP[i][1] = -1;
  }
  DP[45][0] = 0;
  for (int i = 44; i >= 0; i--)
  {
    int64_t mask = (1LL << i);
    int64_t n = 0;
    for (int j = 0; j < N; j++)
    {
      if (A[j] & mask)
        n++; // i番目のbitが1のものを集計する
    }
    if (DP[i + 1][1] >= 0) // Kより小さい場合
    {
      DP[i][1] = max(DP[i][1], DP[i + 1][1] + mask * max(n, N - n));
    }
    if (DP[i + 1][0] >= 0)
    {
      if (K & (1LL << i)) // Kのi桁目のフラグが立っている
      {
        DP[i][1] = max(DP[i][1], DP[i + 1][0] + mask * n); // 0
        DP[i][0] = max(DP[i][0], DP[i + 1][0] + mask * (N - n));
      }
      else
      {
        DP[i][0] = max(DP[i][0], DP[i + 1][0] + mask * n); // 0
      }
    }
  }
  cout << max(DP[0][0], DP[0][1]) << endl;
}
