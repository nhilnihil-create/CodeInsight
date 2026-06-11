#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int n;
  string a, b, c;
  cin >> n >> a >> b >> c;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == b[i] && b[i] != c[i] || a[i] != b[i] && b[i] == c[i] ||
        a[i] == c[i] && b[i] != c[i])
      ans++;
    else if (a[i] != b[i] && b[i] != c[i] && a[i] != c[i])
      ans += 2;
  }
  cout << ans << endl;
  return 0;
}