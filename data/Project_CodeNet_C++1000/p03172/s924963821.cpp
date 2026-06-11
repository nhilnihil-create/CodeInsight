#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 101;
const int MAX_K = 100001;
const int MOD = 1000000007;

int N, K, cum, a[MAX_N], dp[MAX_N][MAX_K];

int add(int a, int b) {
  return (a + b) % MOD;
}
int sub(int a, int b) {
  return (a - b + MOD) % MOD;
}

int main() {
  scanf("%d %d", &N, &K);
  for(int i = 0; i < N; ++i) scanf("%d", &a[i]);

  cum = a[0];
  for(int c = 0; c <= min(cum, K); ++c) dp[0][c] = 1;
  for(int i = 1; i < N; ++i) {
    int r = 0;
    cum += a[i];
    for(int c = 0; c <= min(cum, K); ++c) {
      r = add(r, dp[i - 1][c]);
      if(c > a[i]) r = sub(r, dp[i - 1][c - a[i] - 1]);
      dp[i][c] = r;
    }
  }
  
  printf("%d\n", dp[N - 1][K]);
  return 0;
}