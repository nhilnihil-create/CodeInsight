#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  long long F[N][10], b[10], P[N][11];
  vector<long long> dp(1024);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 10; j++) {
      cin >> F[i][j];
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 11; j++) {
      cin >> P[i][j];
    }
  }
  for (int i = 1; i < 1024; i++) {
    vector<long long> c(N);
    for (int n = i, j = 0; j < 10; n /= 2, j++) {
      b[j] = n%2;
    }
    for (int j = 0; j < 10; j++) {
      for (int k = 0; k < N; k++) {
        c[k] += b[j]*F[k][j];
      }
    }
    for (int j = 0; j < N; j++) {
      dp[i] += P[j][c[j]];
    }
  }
  cout << *max_element(dp.begin()+1,dp.end());
}