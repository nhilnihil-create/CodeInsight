#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  cin >> N;
  long double arr[N];
  for(int i = 0;  i < N; ++i) {
    cin >> arr[i];
  }
  long double dp[N+1][N+1];
  dp[0][0] = 1.0;
  for(int i = 1; i < N+1; ++i) {
    dp[i][0] = dp[i-1][0] * (1-arr[i-1]);
  }
  for(int i = 1; i < N+1; ++i) {
    dp[0][i] = 0.0;
  }
  for(int r = 1; r < N+1; ++r) {
    for(int c = 1; c < N+1; ++c) {
      dp[r][c] = dp[r-1][c-1] * arr[r-1] + (1-arr[r-1]) * dp[r-1][c];
    }
  }
  long double result = 0;
  for(int i = ceil(N/2.0); i < N+1; ++i) {
    result += dp[N][i];
  }
  cout << setprecision(15) << result << "\n";

}