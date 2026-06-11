#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
using ll = long long;
const int INF = (1<<30)-1;
const long long LINF = (1LL<<62)-1;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  rep(i, t) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a < b) {
      cout << "No" << endl;
      continue;
    }
    if (b > d) {
      cout << "No" << endl;
      continue;
    }
    if (c >= b-1) {
      cout << "Yes" << endl;
      continue;
    }
    ll l = c+1-a, r = b-1-a;
    swap(l, r);
    l = -l, r = -r;
    ll g = __gcd(b, d);
    ll p = (l+g-1)/g*g;
    if (p <= r)
      cout << "No" << endl;
    else
      cout << "Yes" << endl;
  }
  return 0;
}