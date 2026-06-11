#include <algorithm>
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

#define rep(i, n) for (int64_t i = 0; i < (n); i++)
#define irep(i, n) for (int64_t i = 0; i <= (n); i++)
#define rrep(i, n) for (int64_t i = (n)-1; i >= 0; i--)
#define rirep(i, n) for (int64_t i = n; i >= 0; i--)

vector<size_t> factors(size_t n) {
  vector<size_t> result;
  for (size_t d = 1; d * d <= n; d++) {
    if (n % d == 0) {
      result.push_back(d);
      if (n / d != d) {
        result.push_back(n / d);
      }
    }
  }
  return result;
}

int main() {
  int64_t N;
  cin >> N;
  vector<size_t> fs = factors(N);

  int64_t result = 0;
  for (int64_t q : fs) {
    int64_t m = N / q - 1;
    if (q < m) {
      result += m;
    }
  }
  cout << result << endl;

  return 0;
}