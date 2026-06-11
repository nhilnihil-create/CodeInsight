#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, v = 1, mv = 0, tmp, x;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> tmp;
    if (abs(tmp) > mv) mv = abs(tmp), v = i, x = (tmp < 0) ? 1 : 0;
  }
  cout << 2 * n - 2 << endl;
  for (int i = 1; i <= n; i++)
    if (i != v) cout << v << " " << i << endl;
  if (x)
    for (int i = n; i > 1; i--) cout << i << " " << i - 1 << endl;
  else
    for (int i = 2; i <= n; i++) cout << i - 1 << " " << i << endl;
}
