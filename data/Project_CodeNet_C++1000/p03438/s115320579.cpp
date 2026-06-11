#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  ll sa = 0, sb = 0, n, cnt = 0, t;
  cin >> n;
  vector<ll> a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];

  rep(i, n) {
    if (a[i] > b[i]) {
      t = a[i] - b[i];
      cnt += t;
      b[i] += t;
    }
  }
  rep(i, n) {
    if (a[i] < b[i]) {
      t = (b[i] - a[i]) / 2;
      a[i] += t * 2;
      cnt -= t;
    }
  }

  cout << (cnt <= 0 ? "Yes" : "No") << endl;
  return 0;
}
