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
  int N;
  cin >> N;
  string s;
  cin >> s;

  vector<int> cnt(26, 0), rcnt(26, 0);
  rep(i, N) { rcnt[s[i] - 'a']++; }

  int result = 0;

  rep(i, N) {
    int j = s[i] - 'a';
    cnt[j]++;
    rcnt[j]--;
    int score = 0;
    rep(k, 26) { score += (cnt[k] > 0 && rcnt[k] > 0 ? 1 : 0); }
    result = max(result, score);
  }

  cout << result << endl;

  return 0;
}