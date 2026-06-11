#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; ++i)
#define repi(i, a, b) for (int i = int(a); i < int(b); ++i)
#define repr(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define ALL(a) (a).begin(), (a).end()
using ll = long long;
// using Graph = vector<vector<int>>;
using P = pair<ll, ll>;
const int dx[] = {0, -1, 0, 1};
const int dy[] = {1, 0, -1, 0};
const ll mod = 1e9 + 7;
const ll INF = 1e9;
const ll LINF = 1LL << 60;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  //////////////////////////////////////
  ll a, b;
  cin >> a >> b;
  if (a % 2 == 0) {
    if ((b - a + 1) % 2 == 0) {
      if ((b - a + 1) / 2 % 2 == 0) {
        cout << 0 << endl;
      } else {
        cout << 1 << endl;
      }
    } else {
      if ((b - a) / 2 % 2 == 0) {
        cout << (0 ^ b) << endl;
      } else {
        cout << (1 ^ b) << endl;
      }
    }
  } else {
    a++;
    if ((b - a + 1) % 2 == 0) {
      if ((b - a + 1) / 2 % 2 == 0) {
        ll ans = 0 ^ (a - 1);
        cout << ans << endl;
      } else {
        ll ans = 1 ^ (a - 1);
        cout << ans << endl;
      }
    } else {
      if ((b - a) / 2 % 2 == 0) {
        cout << (0 ^ b ^ (a - 1)) << endl;
      } else {
        cout << (1 ^ b ^ (a - 1)) << endl;
      }
    }
  }
  return 0;
}
