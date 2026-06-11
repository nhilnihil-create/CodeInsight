#include <bits/stdc++.h>
using namespace std;

// clang-format off
#define forn(i, x, y) for(int i = x; i < y; i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(NULL)
// clang-format on

using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;

const long long MOD = 1000000007;

void add(LL &a, LL b)
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
  VI A(N);
  int k;
  forn(i, 0, N) forn(j, 0, N)
  {
    cin >> k;
    A[i] |= k << j;
  }

  int mask = 1 << N;
  VVLL dp(N + 1, VLL(mask));
  dp[0][mask - 1] = 1;

  for (int i = 0; i < N; i++)
  {
    for (int k = 0; k < mask; k++)
    {
      if (__builtin_popcount(k) != N - i)
        continue;
      for (int j = 0; j < N; j++)
      {
        if (A[i] & k & (1 << j))
          add(dp[i + 1][k - (1 << j)], dp[i][k]);
      }
    }
  }
  cout << dp[N][0] << endl;

  return 0;
}
