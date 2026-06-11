#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll n;
  cin >> n;
  ll k = 10000000000000000;
  rep(i,0,5) {
    ll a;
    cin >> a;
    k = min(k,a);
  }
  ll ans;
  if (n % k == 0) ans = n/k + 4;
  else ans = n/k + 5;
  cout << ans << endl;
  return 0;
}
