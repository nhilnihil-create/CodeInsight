#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int a[3][3];
  rep(i,3)rep(j,3) cin >> a[i][j];
  int x[3], y[3];
  x[0] = 0;
  rep(i,3) y[i] = a[0][i] - x[0];
  rep(i,3) x[i] = a[i][0] - y[0];
  bool ok = true;
  rep(i,3)rep(j,3) {
    if (x[i] + y[j] != a[i][j]) ok = false;
  }
  if (ok) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}