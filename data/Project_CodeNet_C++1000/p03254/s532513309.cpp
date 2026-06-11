#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(all(a));
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (i == n - 1) {
      if (a[i] == x) ans++;
      break;
    }
    if (x < a[i]) break;
    ans++;
    x -= a[i];
  }
  cout << ans << endl;
  return 0;
}