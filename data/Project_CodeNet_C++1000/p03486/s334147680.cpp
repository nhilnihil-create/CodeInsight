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
  vector<vector<int>> cnt(2, vector<int>(26, 0));
  rep(i, 2) {
    string s;
    cin >> s;
    rep(j, s.size()) { cnt[i][s[j] - 'a']++; }
  }

  vector<string> s2(2);

  rep(c, 26) {
    rep(j, cnt[0][c]) { s2[0].push_back(c + 'a'); }
  }
  rrep(c, 26) {
    rep(j, cnt[1][c]) { s2[1].push_back(c + 'a'); }
  }

  cout << (s2[0] < s2[1] ? "Yes" : "No") << endl;

  return 0;
}