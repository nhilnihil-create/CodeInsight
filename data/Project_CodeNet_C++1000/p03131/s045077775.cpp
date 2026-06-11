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
  int64_t K, A, B;
  cin >> K >> A >> B;

  int64_t result = 1;
  int64_t d = min(K, A - 1);
  result += d;
  K -= d;

  if (B - A >= 2) {
    result += (B - A) * (K / 2) + K % 2;
  } else {
    result += K;
  }

  cout << result << endl;
  return 0;
}