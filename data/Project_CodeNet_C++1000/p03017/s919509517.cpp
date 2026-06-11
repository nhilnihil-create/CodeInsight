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
  int N, A, B, C, D;
  cin >> N >> A >> B >> C >> D;

  string s;
  cin >> s;
  s = string("#") + s + string("#");

  vector<bool> p(s.size(), false);
  rep(i, N) { p[i + 1] = s[i] == '.' && s[i + 1] == '.' && s[i + 2] == '.'; }

  bool snuke = true, fnuke = true;
  for (int i = A; i < C; i++) {
    snuke = snuke && (s[i] == '.' || s[i + 1] == '.');
  }
  for (int i = B; i < D; i++) {
    fnuke = fnuke && (s[i] == '.' || s[i + 1] == '.');
  }

  if (C < D) {
    cout << (snuke && fnuke ? "Yes" : "No") << endl;
  } else {
    bool w = false;
    for (int i = B; i <= D; i++) {
      w = w || p[i];
    }
    cout << (snuke && fnuke && w ? "Yes" : "No") << endl;
  }

  return 0;
}