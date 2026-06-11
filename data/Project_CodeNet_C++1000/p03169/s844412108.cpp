#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <vector>
#define DEBUG 1
using namespace std;
constexpr int kMod = 1000000007;
typedef long long LL;

int N;
double dp[301][301][301];

double rec(int c1, int c2, int c3) {
  if (dp[c1][c2][c3] >= 0) return dp[c1][c2][c3];

  double f = N;
  if (c1 > 0) f += c1 * rec(c1-1, c2, c3);
  if (c2 > 0) f += c2 * rec(c1+1, c2-1, c3);
  if (c3 > 0) f += c3 * rec(c1, c2+1, c3-1);

  dp[c1][c2][c3] = f / (c1 + c2 + c3);
  return dp[c1][c2][c3];
}

int main() {
  cin >> N;
  map<int, int> m;
  for (int i = 0; i < N; ++i) {
    int a; cin >> a;
    m[a]++;
  }
  int c1 = m[1], c2 = m[2], c3 = m[3];

  for (int i = 0; i <= N; ++i) {
    for (int j = 0; j <= N; ++j) {
      for (int k = 0; k <= N; ++k) {
        dp[i][j][k] = -1;
      }
    }
  }
  dp[0][0][0] = 0;
  printf("%.10f\n", rec(c1, c2, c3));
}
