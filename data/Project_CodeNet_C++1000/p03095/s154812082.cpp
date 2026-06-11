#include <algorithm>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <queue>
#include <string>
#include <vector>
using namespace std;
using ll = int64_t;
#define rep(i, j, n) for (int i = j; i < (int)n; ++i)
#define rrep(i, j, n) for (int i = (int)n - 1; j <= i; --i)

constexpr ll MOD = 1000000007;
constexpr int INF = 0x3f3f3f3f;
constexpr ll INFL = 0x3f3f3f3f3f3f3f3fLL;

ll alp[26];

int main() {
  int n;
  string s;
  cin >> n >> s;
  rep(i, 0, n) alp[s[i] - 'a']++;

  ll ans = 1;
  rep(i, 0, 26) { ans = ans * (alp[i] + 1) % MOD; }
  ans -= 1;
  cout << ans << endl;
  return 0;
}