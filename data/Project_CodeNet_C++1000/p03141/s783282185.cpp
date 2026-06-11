#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, a, b, ans = 0;
  cin >> n;
  vector<int> c(n);
  rep(i, n) {
    cin >> a >> b;
    c[i] = a + b;
    ans -= b;
  }
  sort(c.rbegin(), c.rend());

  for (int i = 0; i < n; i += 2) ans += c[i];
  cout << ans << endl;

  return 0;
}
