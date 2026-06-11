#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#define rep(i, f, n) for (int i = (f); i < (int)(n); i++)
#define repe(i, f, n) for (int i = (f); i <= (int)(n); i++)
using namespace std;
using ll = long long;
using GraphI = vector<vector<int>>;
using GraphC = vector<vector<char>>;
using pint = pair<int, int>;

const int INF = 1001001001;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> a(2, vector<int>(n));
  rep(y, 0, 2) rep(x, 0, n) cin >> a[y][x];

  int ans = 0;
  rep(i, 0, n) {
    int tot = 0;
    repe(j, 0, i) tot += a[0][j];
    rep(j, i, n) tot += a[1][j];
    ans = max(ans, tot);
  }

  cout << ans << endl;

  return 0;
}
