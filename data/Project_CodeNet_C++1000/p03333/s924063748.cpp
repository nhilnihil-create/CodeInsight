#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> l(n + 1, 0), r(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
  }
  sort(l.begin(), l.end());
  sort(r.begin(), r.end());
  reverse(l.begin(), l.end());
  long long ret = 0;
  for (int i = 0; i < n; i++) {
    int d = l[i] - r[i];
    if (d <= 0) break;
    ret += 2 * d;
  }
  cout << ret << '\n';
  return 0;
}