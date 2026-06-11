#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int INF = 1e9;

int main() {
  ll sa = 0, sb = 0, n, cnt = 0, cnta = 0, cntb = 0;
  cin >> n;
  vector<ll> a(n), b(n);
  rep(i, n) cin >> a[i], sa += a[i];
  rep(i, n) cin >> b[i], sb += b[i];

  rep(i, n) {
    if (a[i] > b[i])
      cnta += (a[i] - b[i]);
    else if (a[i] < b[i])
      cntb += (b[i] - a[i]) / 2;
  }

  cout << (cnta <= cntb ? "Yes" : "No") << endl;
  return 0;
}
