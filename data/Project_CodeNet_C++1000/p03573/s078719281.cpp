#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"

void solve() {
  ll a[3];
  for (ll &i : a)
    cin >> i;
  sort(a, a + 3);
  ll ans = 0;
  if (a[1] == a[0])
    ans = a[2];
  else if (a[1] == a[2])
    ans = a[0];
  cout << ans << endl;
}

int main() {
  ll t;
  t = 1;
  while (t--)
    solve();
  return 0;
}