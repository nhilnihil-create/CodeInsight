#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
#include <cstring>
#include <iomanip>
using namespace std;

double dp[301][301][301];
int main() {
  int n;
  cin >> n;
  int a;
  int cnt[3]= {0};
  for (int i = 0; i < n; ++i) {
    cin >> a;
    cnt[a-1]++;
  }
  int c1 = cnt[0] + cnt[1] + cnt[2];
  int c2 = cnt[1] + cnt[2];
  int c3 = cnt[2];

  dp[0][0][0] = 0;
  double dn = n;
  for (int k = 0; k <= c3; ++k) {
    double dk = k;
    for (int j = 0; j <= c2; ++j) {
      double dj = j;
      for (int i = 0; i <= c1; ++i) {
        double di = i;
        int c = i + j + k;
        if (c <= n && c > 0) {
          dp[i][j][k] = dn / c + di / c * (i > 0 ? dp[i-1][j][k]: 0) +
                                 dj / c * (j > 0 ? dp[i+1][j-1][k]: 0) + 
                                 dk / c * (k > 0 ? dp[i][j+1][k-1]: 0);
        }
      }
    }
  }
  cout << fixed << setprecision(14) << dp[cnt[0]][cnt[1]][cnt[2]] << '\n';
  return 0;
}
