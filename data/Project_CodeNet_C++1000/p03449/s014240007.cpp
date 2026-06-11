#include "bits/stdc++.h"
using namespace std;
using ll = long long;
#define rep(i, begin, n) for (int i = begin; i < n; i++)
#define repe(i, begin, n) for (int i = begin; i <= n; i++)
#define repr(i, begin, n) for (int i = begin; i > begin - n; i--)
#define repre(i, begin, end) for (int i = begin; i >= end; i--)

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}

const int inf = 1000000007;
const int MOD = 1000000007;
const long long INF = 1000000000000000007;

const double pi = 3.141592653589793;
// -------------------------------------------------------
int N;
int A[3][200];
int dp[3][200];

int main() {
  cin >> N;
  repe(i, 1, 2) {
    repe(j, 1, N) { cin >> A[i][j]; }
  }

  dp[1][1] = A[1][1];
  dp[2][1] = dp[1][1] + A[2][1];
  repe(j, 2, N) {
    dp[1][j] = dp[1][j - 1] + A[1][j];
    dp[2][j] = max(dp[2][j - 1], dp[1][j]) + A[2][j];
  }
  cout << dp[2][N] << endl;
}
