#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
using ll = long long;

int N;
vector<vector<vector<double> > > dp;

double rec(int i, int j, int k) {
  if (dp[i][j][k] >= 0) {
    return dp[i][j][k];
  }
  if (i == 0 && j == 0 && k == 0) {
    return 0.0;
  }
  double res = 0.0;
  if (i > 0) {
    res += rec(i - 1, j, k) * i;
  }
  if (j > 0) {
    res += rec(i + 1, j - 1, k) * j;
  }
  if (k > 0) {
    res += rec(i, j + 1, k - 1) * k;
  }
  res += N;
  res *= 1.0 / (i + j + k);

  return dp[i][j][k] = res;
}

int main() {
  cin >> N;
  dp.assign(N + 1, vector<vector<double> >(N + 1, vector<double>(N + 1, -1)));
  int c1 = 0, c2 = 0, c3 = 0;
  rep(i, N) {
    int a;
    cin >> a;
    if (a == 1) {
      c1++;
    } else if (a == 2) {
      c2++;
    } else {
      c3++;
    }
  }
  printf("%.10f\n", rec(c1, c2, c3));
  return 0;
}