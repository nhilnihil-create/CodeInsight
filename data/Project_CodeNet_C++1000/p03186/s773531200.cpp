#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  int ans = b;
  ans += min(b, c);
  c -= min(b, c);
  ans += min(a, c);
  c -= min(a, c);
  if (c > 0)
    ++ans;
  cout << ans << endl;
}