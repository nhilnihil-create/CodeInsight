#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
template <typename T> void chmin(T &a, T b) { a = min(a, b); }
template <typename T> void chmax(T &a, T b) { a = max(a, b); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  string s;
  cin >> n >> k >> s;

  vector<int> v;
  if (s[0] == '1')
    v.push_back(0);

  char bef = s[0];
  int count = 1;
  rep(i, 1, n) {
    if (bef == s[i]) {
      count++;
    } else {
      v.push_back(count);
      count = 1;
    }
    bef = s[i];
  }

  if (count > 0)
    v.push_back(count);

  int vn = v.size();
  vector<ll> acc(vn + 1, 0);
  rep(i, 1, vn + 1) acc[i] = acc[i - 1] + v[i - 1];

  ll ans = 1;

  int start = 1;
  if (acc[1] == 0)
    start = 2;

  for (int i = start; i < vn + 1; i++) {
    if (i & 1) {
      chmax(ans, acc[min(vn, i + (k * 2) - 1)] - acc[i - 1]);
    } else {
      chmax(ans, acc[min(vn, i + (k * 2))] - acc[i - 1]);
    }
  }

  cout << ans << endl;
}
