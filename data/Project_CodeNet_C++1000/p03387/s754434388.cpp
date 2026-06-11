#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> a(3);
  for (int i = 0; i < 3; i++) cin >> a[i];
  sort(a.begin(), a.end());
  int ans = 0;
  ans += a[2] - a[1];
  a[0] += ans;
  ans += (a[2] - a[0] + 1) / 2;
  if ((a[2] - a[0]) % 2 == 1) ans++;
  cout << ans << endl;
}