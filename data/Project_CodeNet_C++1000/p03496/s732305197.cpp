#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
  int n;
  cin >> n;
  vector<ll> v(n);
  rep(i, n) cin >> v[i];
  int p = -1;
  ll ma = -1;
  rep(i, n) {
    if (ma < abs(v[i])) {
      ma = abs(v[i]);
      p = i;
    }
  }
  cout << 2*n - 1 << endl;
  rep(i, n) {
    cout << p+1 << ' ' << i+1 << endl;
  }
  rep(i, (n-1)) {
    int a, b;
    if (v[p] >= 0) {
      a = i+1;
      b = i+2;
    } else {
      a = n-i;
      b = a-1;
    }
    cout << a << ' ' << b << endl;
  }
}
