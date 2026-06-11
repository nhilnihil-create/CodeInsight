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
  vector<int> d(N);
  int64_t s = 0;
  rep(i, N) {
    int a, b;
    cin >> a >> b;
    d[i] = a + b;
    s -= b;
  }

  sort(d.begin(), d.end());
  rep(i, N) {
    if (i % 2 == 0) {
      s += d[N - 1 - i];
    }
  }
  cout << s << endl;

  return 0;
}
