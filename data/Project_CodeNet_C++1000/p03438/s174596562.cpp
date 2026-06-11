#include <algorithm>
#include <bitset>
#include <boost/rational.hpp>
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

int main() {
  int N;
  cin >> N;

  int64_t K = 0;
  vector<int> a(N), b(N);
  rep(i, N) {
    cin >> a[i];
    K -= a[i];
  }
  rep(i, N) {
    cin >> b[i];
    K += b[i];
  }

  rep(i, N) { K -= max((b[i] - a[i] + 1) / 2, 0); }
  cout << (K >= 0 ? "Yes" : "No") << endl;

  return 0;
}
