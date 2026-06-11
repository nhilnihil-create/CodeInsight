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

  string buf;
  cout << 0 << endl;
  cin >> buf;
  if (buf[0] == 'V') {
    return 0;
  }

  char ls = buf[0], us = buf[0];
  int lb = 0, ub = N;
  rep(i, 19) {
    const int mid = (lb + ub) / 2;
    cout << mid << endl;
    string buf;
    cin >> buf;
    if (buf[0] == 'V') {
      break;
    }

    const int len = mid - lb + 1;
    if ((len % 2 == 0) == (buf[0] == ls)) {
      ub = mid;
      us = buf[0];
    } else {
      lb = mid;
      ls = buf[0];
    }
  }

  return 0;
}
