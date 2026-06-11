#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];

  vector<ll> neg;
  int z = 0;
  rep(i,n) {
    if (a[i] < 0) neg.push_back(a[i]);
    if (a[i] == 0) z++;
  }

  ll ans = 0;
  rep(i,n) ans += abs(a[i]);

  if (neg.size() % 2 == 1 && z == 0) {
    ll mn = 100100100;
    rep(i,n) mn = min(mn,abs(a[i]));
    ans -= mn*2;
  }
  cout << ans << endl;
}