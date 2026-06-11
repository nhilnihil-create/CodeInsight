#include <bits/stdc++.h>
using namespace std;

long long x[1005];
long long y[1005];

int main() {
  int n;
  cin >> n;
  bool odd = false, even = false;
  for (int ni = 0; ni < n; ni++) {
    cin >> x[ni] >> y[ni];
    if (abs(x[ni] + y[ni]) % 2 == 0) even = true;
    else odd = true;
  }
  if (odd && even) {
    cout << -1 << endl;
    return 0;
  }
  if (even) {
    cout << 33 << endl;
    cout << "1 ";
    for (int ni = 0; ni < n; ni++) {
      x[ni]--;
    }
  } else {
    cout << 32 << endl;
  }
  for (int i = 31; i >= 0; i--) {
    cout << (1LL << i) << " ";
  }
  cout << endl;
  for (int ni = 0; ni < n; ni++) {
    if (even) {
      cout << "R";
    }
    long long l = 1LL << 31;
    while (l > 0) {
      if (x[ni] + y[ni] > 0) {
        if (x[ni] - y[ni] > 0) {
          cout << "R";
          x[ni] -= l;
        } else {
          cout << "U";
          y[ni] -= l;
        }
      } else {
        if (x[ni] - y[ni] > 0) {
          cout << "D";
          y[ni] += l;
        } else {
          cout << "L";
          x[ni] += l;
        }
      }
      l >>= 1;
    }
    cout << "\n";
  }
  return 0;
}