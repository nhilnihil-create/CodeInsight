//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()


int main() {
  ll a, b, c, k;
  cin >> a >> b >> c >> k;
  ll ans;
  if (k%2 == 0) ans = a-b;
  else ans = b-a;
  if (abs(ans) > 1e18) puts("Unfair");
  else cout << ans << endl;
  return 0;
}