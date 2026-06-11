#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> a(3);
  cin >> a[0] >> a[1] >> a[2];
  sort(a.begin(), a.end());
  int ans = a[2] * 2 - a[0] - a[1];
  if (ans & 1) cout << (ans + 3) / 2 << endl;
  else cout << ans / 2 << endl;
}