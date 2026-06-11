#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
#define rrep(i, j, n) for (int i = (int)n - 1; j <= i; --i)

int main() {
  string s;
  ll k;
  cin >> s >> k;
  ll n = (ll)s.size();
  rep(i, 0, min(n, k)) {
    if (i == k - 1 || s[i] != '1') {
      cout << s[i] << endl;
      return 0;
    }
  }

  return 0;
}