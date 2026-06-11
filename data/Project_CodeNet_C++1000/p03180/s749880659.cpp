#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
#define chmax(x, v) do { x = max(x, v); } while (0)
#define chmin(x, v) do { x = min(x, v); } while (0)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

using namespace std;

ll N;
ll a[20][20];
ll sum[1000000]; // sum[S]: 集合Sに含まれる要素の和
ll dp[1000000]; // dp[S]: 集合Sの要素をグループ分けした時の得点の最大値

signed main() {
  cin >> N;
  rep(i, N) rep(j, N) cin >> a[i][j];
  for (ull S = 0; S < (1 << N); S++)
    for (int i=0; i<N; i++)
      for (int j=i+1; j<N; j++)
        if ((S & (1 << i)) && (S & (1 << j)))
          sum[S] += a[i][j];
  dp[0] = 0; // 空集合
  for (ull S = 1; S < (1 << N); S++) {
    dp[S] = sum[S];
    for (ull U = (S-1) & S; ; U = (U-1) & S) { // Sの真部分集合
      chmax(dp[S], dp[U] + sum[S - U]);
      if (U == 0) break;
    }
  }
  cout << dp[(1 << N) - 1] << endl;
  return 0;
}
