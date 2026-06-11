#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
  int n, x;
  cin >> n >> x;

  int dd[n];
  for (int i = 0; i < n; i++) {
    int xx;
    cin >> xx;
    dd[i] = abs(x - xx);
  }

  if (n == 1) {
    cout << dd[0] << endl;
    return 0;
  }

  int ans = gcd(dd[0], dd[1]);
  for (int i = 2; i < n; i++) {
    ans = gcd(ans, dd[i]);
  }

  cout << ans << endl;

  return 0;
}