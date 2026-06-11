#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];

  ll ca = 0, cb = 0;
  rep(i, n) {
    if (a[i] > b[i]) {
      cb += a[i] - b[i];
    } else {
      ca += (b[i] - a[i] + 1) / 2;
      cb += (b[i] - a[i]) % 2;
    }
  }

  cout << (ca >= cb ? "Yes" : "No") << endl;
  return 0;
}
