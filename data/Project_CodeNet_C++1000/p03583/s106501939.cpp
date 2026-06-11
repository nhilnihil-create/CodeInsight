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
  int64_t N;
  cin >> N;

  for (int h = 1; h <= 3500; h++)
    for (int n = h; n <= 3500; n++) {
      int64_t a = 4 * h * n - N * n - N * h, b = N * h * n;
      if (a > 0 && b % a == 0) {
        cout << h << " " << n << " " << b / a << endl;
        return 0;
      }
    }

  return 0;
}