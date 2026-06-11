#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  int c[3][3];
  rep(i, 3) rep(j, 3) cin >> c[i][j];
  int a[3], b[3];
  a[0] = 0, b[0] = c[0][0], b[1] = c[0][1], b[2] = c[0][2];
  a[1] = c[1][0] - b[0], a[2] = c[2][0] - b[0];
  bool flag = true;
  rep(i, 3) rep(j, 3) {
    if (c[i][j] != a[i] + b[j]) flag = false;
  }
  if (flag)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}