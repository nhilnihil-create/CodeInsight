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

  VLL dp(1 << N);
  dp[0] = 1;
  for (int mask = 1; mask < (1 << N); mask++)
  {
    int m = __builtin_popcount(mask) - 1;
    for (int w = 0; w < N; w++)
    {
      if (mask & A[m] & (1 << w))
        add(dp[mask], dp[mask ^ (1 << w)]);
    }
  }
  cout << dp[(1 << N) - 1] << endl;

  return 0;
}
