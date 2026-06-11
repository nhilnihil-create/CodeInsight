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

int main() {
  string s;
  cin >> s;

  int result = 0;
  int sum = 0;
  rep(i, s.size()) {
    int d = s[i] - '0';
    sum += d;
    if (d > 0) {
      int z = sum - 1 + 9 * (s.size() - 1 - i);
      result = max(result, z);
    }
  }
  result = max(result, sum);
  cout << result << endl;

  return 0;
}