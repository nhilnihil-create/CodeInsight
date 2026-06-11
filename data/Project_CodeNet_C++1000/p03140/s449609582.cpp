#include <iostream>
#include <string>

using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  string a, b, c;
  cin >> a >> b >> c;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    const int x = (a[i] == b[i]) + (b[i] == c[i]) + (c[i] == a[i]);
    if (x == 1 || x == 2) ans++;
    if (x == 0) ans += 2;
  }
  cout << ans << endl;
  return 0;
}
