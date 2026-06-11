#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
// clang-format on

const long long MOD = 1000000007;

using LL = long long;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using VVLL = vector<VLL>;

template <typename T>
void add(T &a, T b)
{
  a += b;
  if (a >= MOD)
    a -= MOD;
}

int main()
{
  IOS;

  int N;
  cin >> N;
  string s;
  cin >> s;

  VVLL dp(N, VLL(N));
  for (int i = 0; i < N; i++)
    dp[0][i] = 1;

  for (int i = 1; i < N; i++)
  {
    if (s[i - 1] == '<')
    {
      for (int j = 0; j < N - i; j++)
      {
        dp[i][j] = dp[i - 1][j];
        if (j > 0)
          add(dp[i][j], dp[i][j - 1]);
      }
    }
    else
    {
      for (int j = N - i - 1; j >= 0; j--)
      {
        dp[i][j] = dp[i][j + 1];
        add(dp[i][j], dp[i - 1][j + 1]);
      }
    }
  }

  cout << dp[N - 1][0] << endl;

  return 0;
}
