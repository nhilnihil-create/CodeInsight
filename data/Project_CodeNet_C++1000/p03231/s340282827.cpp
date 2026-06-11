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

int64_t gcd(int64_t a, int64_t b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

int main() {
  int64_t N, M;
  cin >> N >> M;

  string s, t;
  cin >> s >> t;

  const int64_t d = gcd(N, M);
  bool result = true;
  rep(i, d) { result = result && (s[N / d * i] == t[M / d * i]); }
  cout << (result ? N * M / d : -1) << endl;

  return 0;
}