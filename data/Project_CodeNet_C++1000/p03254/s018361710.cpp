#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n >> x;
  int a[n];
  for (int i=0; i < n; i++) cin >> a[i];
  sort(a, a + n);
  int res =0;
  for (int i=0; i < n; i++) {
    if (x>=a[i]) {
      x -= a[i];
      res++;
    }
    else {
    x = 0;
    break;
    }
  }
  if (res > 0 && x > 0 ) res -= 1;
  cout << res << endl;
}