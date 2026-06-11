#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >> n;
  int x[n], y[n];
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    y[i] = x[i];
  }

  sort(x, x + n);

  int med_l = x[n / 2 - 1];
  int med_r = x[n / 2];
  for (int i = 0; i < n; i++) {
    if (y[i] <= med_l) {
      cout << med_r;
    } else {
      cout << med_l;
    }
    if (i < n - 1) {
      cout << '\n';
    } else {
      cout << endl;
    }
  }
  return 0;
}
