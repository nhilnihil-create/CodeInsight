#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <utility>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <cstdio>
#include <cstring>
#include <cmath>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int MOD = 1e9+7;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> c(n);
  rep(i, n) cin >> c[i];
  vector<ll> dp(n+1);
  dp[0] = 1;
  vector<int> idx(2*1e5+1, -1);
  idx[c[0]] = 0;
  for (int i=1; i<=n; i++) {
    dp[i] = dp[i-1];
    if (idx[c[i]] >= 0 && c[i] != c[i-1])
      (dp[i] += dp[idx[c[i]]]) %= MOD;
    idx[c[i]] = i;
  }
  cout << dp[n] << endl;
  return 0;
}