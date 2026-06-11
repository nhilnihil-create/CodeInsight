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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<ll> s;
  rep(i, n) {
    ll sum = 0;
    for (int j = i ; j >= 0; j--) {
      sum += a[j];
      s.push_back(sum);
    }
  }
  for (int i = 62; i >= 0; i--) {
    vector<ll> ok;
    rep(j, s.size()) {
      if (s[j] & 1LL<<i)
        ok.push_back(s[j]);
    }
    if (ok.size() >= k)
      s = ok;
  }
  ll ans = s[0];
  for (int i = 1; i < s.size(); i++)
    ans &= s[i];
  cout << ans << endl;
  return 0;
}