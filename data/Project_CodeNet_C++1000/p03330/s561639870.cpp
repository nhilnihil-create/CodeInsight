#include <cstdio>
#include <climits>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <climits>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#include <set>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
long long MOD = 1000000007;
long long INF = 1000000000000000; //10^15
typedef long long ll;
typedef unsigned long long ull;

int main(void) {

  int n, C, d[501][501], c[501][501];
  cin >> n >> C;
  rep(i, C) rep(j, C) cin >> d[i][j];
  rep(i, n) rep(j, n) {
    cin >> c[i][j];
    c[i][j]--;
  }

  vector<int> col[3];
  rep(i, n) rep(j, n) col[(i + j) % 3].push_back(c[i][j]);

  int ans[3][40] = {};
  rep(i, C) {
    rep(j, 3) rep(k, col[j].size()) ans[j][i] += d[col[j][k]][i];
  }

  int a =INT_MAX;
  rep(i, C) rep(j, C) rep(k, C) {
    if (i != j && j != k && k != i) {
      a = min(a, ans[0][i]+ans[1][j]+ans[2][k]);
    }
  }
  cout << a << endl;

  return 0;

}
