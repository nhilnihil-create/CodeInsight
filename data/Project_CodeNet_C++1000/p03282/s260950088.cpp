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
  int n = (int)s.size();
  int i = 0;
  while (i < n && s[i] == '1') ++i;
  int last = s[i] - '0';

  if (i < k)
    cout << last << endl;
  else
    cout << 1 << endl;

  return 0;
}
