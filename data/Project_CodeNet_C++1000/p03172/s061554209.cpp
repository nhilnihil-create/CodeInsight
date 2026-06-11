#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 101;
const ll MAX_K = 100001;
const ll MOD = 1000000007;

int N;
ll K, cum, a[MAX_N], dp[MAX_N][MAX_K];

ll add(ll a, ll b) {
  return (a + b) % MOD;
}
ll sub(ll a, ll b) {
  return (a - b + MOD) % MOD;
}

int main() {
  scanf("%d %lld", &N, &K);
  for(int i = 0; i < N; ++i) scanf("%lld", &a[i]);

  for(ll c = 0; c <= min(a[0], K); ++c) dp[0][c] = 1ll;
  cum = a[0];
  for(int i = 1; i < N; ++i) {
    ll r = 0ll;
    for(ll c = 0; c <= min(a[i], K); ++c) {
      r = add(r, dp[i - 1][c]);
      dp[i][c] = r;
    }
    cum += a[i];
    for(ll c = a[i] + 1; c <= min(cum, K); ++c) {
      r = add(r, dp[i - 1][c]);
      r = sub(r, dp[i - 1][c - a[i] - 1]);
      dp[i][c] = r;
    }
  }
  
  printf("%lld\n", dp[N - 1][K]);
  return 0;
}