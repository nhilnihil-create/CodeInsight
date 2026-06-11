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
  int n, q;
  string s;
  cin >> n >> q >> s;
  vector<char> t(q), d(q);
  rep(i, q) cin >> t[i] >> d[i];
  int l = 0, r = n+1;
  while (r-l > 1) {
    int mid = (l+r)/2;
    int p = mid;
    rep(i, q) {
      if (t[i] == s[p-1]) {
        if (d[i] == 'R')
          p++;
        else
          p--;
      }
    }
    if (p)
      r = mid;
    else
      l = mid;
  }
  int res = l;
  l = 0, r = n+1;
  while (r-l > 1) {
    int mid = (l+r)/2;
    int p = mid;
    rep(i, q) {
      if (t[i] == s[p-1]) {
        if (d[i] == 'R')
          p++;
        else
          p--;
      }
    }
    if (p == n+1)
      r = mid;
    else
      l = mid;
  }
  res += n-(r-1);
  int ans = max(n-res, 0);
  cout << ans << endl;
  return 0;
}