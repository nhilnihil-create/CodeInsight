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
  string s;
  cin >> s;

  string t("keyence");

  const int M = s.size() - t.size();
  bool result = false;
  for (int i = 0; i + M <= s.size(); i++) {
    bool match = true;
    for (int j = 0; j < i; j++) {
      match = match && (s[j] == t[j]);
    }
    for (int j = i + M; j < s.size(); j++) {
      match = match && (s[j] == t[j - (i + M) + i]);
    }
    result = result || match;
  }

  cout << (result ? "YES" : "NO") << endl;
  return 0;
}