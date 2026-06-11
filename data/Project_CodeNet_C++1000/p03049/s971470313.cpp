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

int main() {
  int N;
  cin >> N;
  vector<string> s(N);
  rep(i, N) { cin >> s[i]; }

  int a = 0, b = 0, c = 0;
  int result = 0;
  rep(i, N) {
    if (s[i].back() == 'A') {
      if (s[i].front() == 'B') {
        c++;
      } else {
        a++;
      }
    } else if (s[i].front() == 'B') {
      b++;
    }

    rep(j, s[i].size() - 1) {
      if (s[i][j] == 'A' && s[i][j + 1] == 'B') {
        result++;
      }
    }
  }
  cerr << result << endl;

  if (c > 0) {
    result += c - 1;
    if (a > 0) {
      result++;
    } else {
      a = 1;
    }
    result += min(a, b);
  } else {
    result += min(a, b);
  }

  cerr << a << " " << b << " " << c << endl;
  cout << result << endl;

  return 0;
}