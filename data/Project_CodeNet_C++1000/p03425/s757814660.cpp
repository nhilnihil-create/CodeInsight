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
  int n;
  cin >> n;
  string s;
  unordered_map<char, ll> cnt;
  rep(i, 0, n) {
    cin >> s;
    cnt[s[0]]++;
  }

  ll all = 0;
  char c[5]{'M', 'A', 'R', 'C', 'H'};
  rep(i, 0, 5) rep(j, i + 1, 5) rep(k, j + 1, 5) all +=
    cnt[c[i]] * cnt[c[j]] * cnt[c[k]];
  cout << all << endl;

  return 0;
}