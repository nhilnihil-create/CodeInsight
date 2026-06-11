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
#include <cstring>
#include <cmath>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int MAX = 200100;
int BIT[MAX];
void add(int i, int n) {
  while (i < MAX) {
    BIT[i] += n;
    i += i & -i;
  }
}
int sum(int i) {
  int res = 0;
  while (i > 0) {
    res += BIT[i];
    i -= i & -i;
  }
  return res;
}
void clear() {
  for (int i = 1; i < MAX; i++)
    BIT[i] = 0;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  int l = 0, r = 1e9;
  const ll all = (n+1)*n/2;
  while (r-l > 1) {
    int mid = (l+r)/2;
    vector<int> b(n), s(n+1);
    rep(i, n) b[i] = (a[i]<=mid ? 1 : -1);
    rep(i, n) s[i+1] = s[i]+b[i];
    rep(i, n+1) s[i] += n+1;
    add(s[0], 1);
    ll num = 0;
    for (int i = 1; i <= n; i++) {
      num += sum(s[i]-1);
      add(s[i], 1);
    }
    clear();
    if (num >= all/2+1)
      r = mid;
    else
      l = mid;
  }
  cout << r << endl;
  return 0;
}