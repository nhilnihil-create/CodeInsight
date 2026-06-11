#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, k;
  cin >> m >> k;
  
  if (k == 0) {
    for (int i=0; i<(1<<m); ++i) {
      cout << i << ' ' << i << ' ';
    }
    cout << endl;
  } else if (m == 1 || (1<<m) <= k) {
    cout << -1 << endl;
  } else {
    cout << 0 << ' ' << k << ' ' << 0 << ' ';
    for (int i=1; i<(1<<m); ++i) {
      if (i != k) cout << i << ' ';
    }
    cout << k << ' ';
    for (int i=(1<<m)-1; i>0; --i) {
      if (i != k) cout << i << ' ';
    }
    cout << endl;
  }
  return 0;
}
