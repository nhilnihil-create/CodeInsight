#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int n;
  cin >> n;
  vector<int> x(n);
  rep(i, n) cin >> x[i];

  vector<int> y(n);
  rep(i, n) y[i] = x[i];
  sort(y.begin(), y.end());
  int m1 = y[n / 2 - 1];
  int m2 = y[n / 2];
  vector<int> b(n);
  rep(i, n) {
    if (x[i] <= m1) b[i] = m2;
    else b[i] = m1;
  }
  rep(i, n) cout << b[i] << endl;
  return 0;
}