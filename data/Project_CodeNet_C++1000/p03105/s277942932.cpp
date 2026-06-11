#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

void solve() {
  ll a, b, c, ans = 0;
  cin >> a >> b >> c;
  cout << min((1ll * b / a), c) << endl;
}

int main() {
  ll t;
  // cin >> t;
  t = 1;
  while (t--)
    solve();
  return 0;
}