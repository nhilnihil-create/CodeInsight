#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using P = pair<ll, ll>;
template <class T>
using V = vector<T>;

int main() {
  int n;
  cin >> n;
  V<string> s(n);
  rep(i, n) cin >> s[i];

  int ans(0);
  rep(i, n) {
    int S = s[i].length();
    rep(j, S - 1) {
      if (s[i][j] == 'A' && s[i][j + 1] == 'B') ans++;
    }
  }
  int a(0), b(0), ab(0);
  rep(i, n) {
    if (s[i].back() == 'A' && s[i][0] == 'B')
      ab++;
    else if (s[i].back() == 'A')
      a++;
    else if (s[i][0] == 'B')
      b++;
  }
  if (ab > 1) ans += ab - 1;
  if (ab > 0) {
    if (a > 0) {
      a--;
      ans++;
    }
    if (b > 0) {
      b--;
      ans++;
    }
  }
  ans += min(a, b);
  cout << ans << endl;
}
