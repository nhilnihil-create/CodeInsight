#include <bits/stdc++.h>
using namespace std;
const int64_t MOD = 1000000007;
int N;
int64_t dp[22][(1 << 21)];
bool A[21][21];

void init()
{
  for (int i = 0; i < 22; i++)
  {
    for (int j = 0; j < (1 << 21); j++)
    {
      dp[i][j] = -1;
    }
  }
}

int64_t rec(int i, int64_t bit)
{
  if (i == N)
  {
    return 1;
  }
  if (dp[i][bit] != -1)
    return dp[i][bit];
  int64_t ret = 0;
  for (int j = 0; j < N; j++)
  {
    if (A[i][j] && !(bit & (1 << j)))
    {
      (ret += rec(i + 1, (bit | (1 << j)))) %= MOD;
    }
  }
  return dp[i][bit] = ret;
}

int main()
{
  cin >> N;
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      cin >> A[i][j];
    }
  }
  init();
  cout << rec(0, 0) << endl;
}
