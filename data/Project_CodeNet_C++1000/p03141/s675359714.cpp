#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
  ll n, btot = 0;
  cin >> n;
  vector<ll> t(n),a(n),b(n);
  rep(i, n) {
    cin >> a[i] >> b[i];
    t[i] = a[i] + b[i];
    btot += b[i];
  }

  sort(t.rbegin(), t.rend());
  ll ans = -btot;
  for (int i = 0; i < n; i += 2) ans += t[i];
  cout << ans << endl;
  return 0;
}