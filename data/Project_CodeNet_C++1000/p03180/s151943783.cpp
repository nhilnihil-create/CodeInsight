#include <iostream>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0,_i=(n);i<_i;++i)
int N;
ll A[16][16], dp[1<<16], dp2[1<<16];
constexpr ll INF = 1e18;
ll dfs(int bit) {
  if (__builtin_popcount(bit) == N) return 0;
  if (dp[bit] != INF) return dp[bit];

  const int S = ((1 << N)-1) ^ bit;
  ll ans = 0;
  for (int T = S;; T = (T-1) & S) {
    if (T == 0) break;
    if (dp2[T] != INF) {
      ans = max(ans, dfs(bit | T) + dp2[T]);
      continue;
    }
    ll tmp = 0;
    rep(i, N) rep(j, N) {
      if (i >= j)
        continue;
      if ((T & (1 << i)) && (T & (1 << j)))
        tmp += A[i][j];
    }
    dp2[T] = tmp;
    ans = max(ans, dfs(bit | T) + tmp);
  }
  return dp[bit] = ans;
}

int main() {
  cin >> N;
  rep(i, N) rep(j, N)
    cin >> A[i][j];
  rep(i, 1  << N)
    dp[i] = dp2[i] = INF;
  cout << dfs(0) << endl;

  return 0;
}
