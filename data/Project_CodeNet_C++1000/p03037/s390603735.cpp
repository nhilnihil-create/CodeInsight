#include <iostream>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  int lmax = 1, rmin = n;
  while (m--) {
    int l, r;
    cin >> l >> r;
    lmax = max(l, lmax);
    rmin = min(r, rmin);
  }
  int ans = rmin - lmax + 1;
  cout << (ans < 0 ? 0 : ans) << endl;
}