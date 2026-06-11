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

  vector<int> black(N + 1, 0), white(N + 1, 0);
  rep(i, N) { black[i + 1] = black[i] + (s[i] == '#' ? 1 : 0); }
  rrep(i, N) { white[i] = white[i + 1] + (s[i] == '.' ? 1 : 0); }

  int result = N;
  irep(i, N) { result = min(result, black[i] + white[i]); }
  cout << result << endl;

  return 0;
}