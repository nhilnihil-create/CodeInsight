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
  int k;
  cin >> k;
  vector<ll> a(k);
  rep(i, k) cin >> a[i];
  ll mn = 2, mx = 2;
  for (int i = k-1; i >= 0; i--) {
    mn = (mn+a[i]-1)/a[i]*a[i];
    mx = mx/a[i]*a[i]+a[i]-1;
    if (mx < mn) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << mn << ' ' << mx << endl;
  return 0;
}