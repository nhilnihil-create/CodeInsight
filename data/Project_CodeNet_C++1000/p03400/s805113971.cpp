#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int d, x;
  cin >> d >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    x++;
    int t = 1 + a[i];
    while (t <= d) {
      x++;
      t += a[i];
    }
  }
  cout << x << endl;
  return 0;
}