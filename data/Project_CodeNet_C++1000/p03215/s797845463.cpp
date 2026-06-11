#include <cstdio>
#include <climits>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdio>
#include <climits>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#include <set>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
long long MOD = 1000000007;
long long INF = 1000000000000000; //10^15
typedef long long ll;
typedef unsigned long long ull;

int main(void) {
  int n, k;
  ll a[1010], s[1010] = {};

  cin >> n >> k;
  rep(i, n) cin >> a[i];

  rep(i, n) s[i + 1] = s[i] + a[i];

  vector<ll> b; int m = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      b.push_back(s[j] - s[i]);
      m++;
    }
  }

  ll ma = 0;
  for (int i = 0; i < m; i++) {
    ma = max(ma, b[i]);
  }
  int l = 0;
  while (ma / (1LL << l) > 0) l++;
  /*cout << l << endl;
  rep(i, b.size()) {
    if (b[i] < 10) cout << " ";
    cout << b[i] << " ";
    for (int j = l; j >= 0; j--) {
      cout << ((b[i] >> j) & 1);
    } cout << endl;
  }
  cout << endl;*/

  vector<ll> c;
  for (int i = l; i >= 0; i--) {
    c.clear();
    for (int j = 0; j < b.size(); j++) {
      if ((b[j] >> i) & 1) c.push_back(b[j]);
    }
    if (c.size() >= k) {
      //for (int j = 0; j < c.size(); j++) cout << c[j] << endl;
      //cout << endl;
      b.clear();
      for (int j = 0; j < c.size(); j++) b.push_back(c[j]);
    }
  }

  /*rep(i, b.size()) {
    cout << b[i] << " ";
    for (int j = l; j >= 0; j--) {
      cout << ((b[i] >> j) & 1);
    } cout << endl;
    }*/
  ll ans = b[0];
  for (int i = 0; i < k; i++) ans &= b[i];
  cout << ans << endl;
}
