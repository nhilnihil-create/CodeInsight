#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAX_N = 401;
const ll INF = LLONG_MAX;

int N;
ll a[MAX_N], dp[MAX_N][MAX_N];

int main() {
  scanf("%d", &N);
  for(int i = 0; i < N; ++i) {
    scanf("%lld", &a[i]);
    dp[i][i] = a[i];
    if(i) a[i] += a[i - 1];
  }

  for(int i = 1; i < N; ++i) dp[i - 1][i] = dp[i - 1][i - 1] + dp[i][i];
  for(int d = 2; d < N; ++d) {
    for(int i = 0; i + d < N; ++i) {
      int j = i + d;
      ll cost = i ? a[j] - a[i - 1] : a[j];
      ll mn = min(dp[i + 1][j], dp[i][j - 1]);
      for(int k = i + 1; k + 1 < j; ++k) {
        mn = min(mn, dp[i][k] + dp[k + 1][j]);
      }
      dp[i][j] = mn + cost;
    }
  }
  
  printf("%lld\n", dp[0][N - 1]);
  return 0;
}