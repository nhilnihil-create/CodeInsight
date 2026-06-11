#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <cmath>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int lim[51000];

int dp[5][210];

int main() {
  int N; cin >> N;
  vector<int> t(N), v(N);
  for (int i = 0; i < N; ++i) cin >> t[i], t[i] *= 2;
  int sum = 0;
  for (int i = 0; i < N; ++i) {
    cin >> v[i], v[i] *= 2;
    for (int j = sum; j < sum + t[i]; ++j) {
      lim[j] = v[i];
    }
    sum += t[i];
  }
  for (int i = 0; i < 5; ++i) for (int j = 0; j < 210; ++j) dp[i][j] = -(1<<29);
  dp[0][0] = 0;
  for (int i = 0; i < sum; ++i) {
    for (int j = 0; j < 210; ++j) {
      if (j + 1 <= min(lim[i], lim[i+1])) chmax(dp[(i+1)%2][j+1], dp[i%2][j] + j*2+1);
      if (j <= min(lim[i], lim[i+1])) chmax(dp[(i+1)%2][j], dp[i%2][j] + j*2);
      if (j - 1 >= 0 && j - 1 <= min(lim[i], lim[i+1])) chmax(dp[(i+1)%2][j-1], dp[i%2][j] + j*2-1);
    }

    for (int j = 0; j < 210; ++j) dp[i%2][j] = -(1<<29);
  }
  cout << fixed << setprecision(10) << (double)dp[0][0] / 8 << endl;
  return 0;
}
