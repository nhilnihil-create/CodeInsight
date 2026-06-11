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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  rep(i, n) {
    if (!i && a[i] != 0 || i && a[i]-a[i-1] > 1) {
      cout << -1 << endl;
      return 0;
    }
  }
  ll ans = 0;
  rep(i, n) {
    if (i == n-1 || a[i+1]-a[i] < 1)
      ans += a[i];
  }
  cout << ans << endl;
  return 0;
}