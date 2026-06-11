#include <bits/stdc++.h>
#define rep(i, n) for (lli i = 0; i < (n); i++)
#define rrep(i, n) for (lli i = (n)-1; i >= 0; i--)
using namespace std;
using lli = long long int;
#define int long long int
void YESNO(bool), YesNo(bool);
template <class T1, class T2>
bool chmin(T1 &l, const T2 &r);
template <class T1, class T2>
bool chmax(T1 &l, const T2 &r);
lli dp[1 << 20] = {};
void solve(long long N, std::vector<std::vector<long long>> a)
{
  // dp[mask] := maskを使ったときのoptimalな分け方
  // dp[mask] := max(maskは全部一緒, dp[a] + dp[b] {a, bは少なくとも分ける}){a, b}
  dp[0] = 0;
  rep(i, 1 << N)
  {
    if (!i)
      continue;
    dp[i] = -1e18;

    lli tmp = 0;
    rep(j, N) rep(k, j)
    {
      if (((i >> j) & (i >> k)) & 1)
      {
        tmp += a[j][k];
      }
    }
    dp[i] = tmp;
    for (lli T = i; T; T = (T - 1) & i)
    {
      if (T == 0)
        break;
      chmax(dp[i], (dp[T] + dp[i ^ T]));
    }
  }

  cout << dp[(1 << N) - 1] << endl;
}

signed main()
{
  long long N;
  scanf("%lld", &N);
  std::vector<std::vector<long long>> a(N, std::vector<long long>(N));
  for (int i = 0; i < N; i++)
  {
    for (int j = 0; j < N; j++)
    {
      scanf("%lld", &a[i][j]);
    }
  }
  solve(N, std::move(a));
  return 0;
}

// -- lib
void YESNO(bool b) { cout << (b ? "YES" : "NO") << endl; }
void YesNo(bool b) { cout << (b ? "Yes" : "No") << endl; }

template <class T1, class T2>
bool chmin(T1 &l, const T2 &r)
{
  return (l > r) ? (l = r, true) : false;
}

template <class T1, class T2>
bool chmax(T1 &l, const T2 &r)
{
  return (l < r) ? (l = r, true) : false;
}
