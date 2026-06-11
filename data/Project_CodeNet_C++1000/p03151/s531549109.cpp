#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <tuple>
#include <vector>

using namespace std;

#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (int64_t)(n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

#define chmax(a, b) (a) = max(a, b)
#define chmin(a, b) (a) = min(a, b)

int main() {
  int N;
  cin >> N;

  vector<int> a(N), b(N);
  rep(i, N) { cin >> a[i]; }
  rep(i, N) { cin >> b[i]; }

  vector<int> c(N);
  rep(i, N) { c[i] = a[i] - b[i]; }
  sort(c.begin(), c.end());

  int cnt = 0;
  int64_t r = 0;
  rep(i, N) {
    if (c[i] < 0) {
      cnt++;
      r -= c[i];
    }
  }

  rrep(i, N) {
    if (r > 0) {
      r -= min((int64_t)c[i], r);
      cnt++;
    }
  }

  cout << (r > 0 ? -1 : cnt) << endl;
  return 0;
}