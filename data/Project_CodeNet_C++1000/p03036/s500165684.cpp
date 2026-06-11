#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;

int main() {
  int r, d, x0;
  cin >> r >> d >> x0;
  vector<int> x(11);
  x.at(0) = x0;
  rep(i, 10) {
    x.at(i + 1) = r * x.at(i) - d;
  }
  rep(i, 10) cout << x.at(i + 1) << endl;
}