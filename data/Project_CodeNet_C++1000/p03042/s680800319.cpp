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
  string s;
  cin >> s;

  int a = 10 * (s[0] - '0') + (s[1] - '0');
  int b = 10 * (s[2] - '0') + (s[3] - '0');

  bool ym = (b >= 1 && b <= 12), my = (a >= 1 && a <= 12);
  if (ym && my) {
    cout << "AMBIGUOUS" << endl;
  } else if (ym && !my) {
    cout << "YYMM" << endl;
  } else if (!ym && my) {
    cout << "MMYY" << endl;
  } else {
    cout << "NA" << endl;
  }
  return 0;
}