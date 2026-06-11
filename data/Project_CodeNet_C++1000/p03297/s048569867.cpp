#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int BIG = 2e9 + 55;
ll a, b, c, d;

void solve(){
  if(a - b < 0){
    cout << "No\n";
    return;
  }

  if(d - b < 0){
    cout << "No\n";
    return;
  }

  ll delta = __gcd(b, d);
  ll lo = ((c + 1 - b - a) / delta) - 10;
  ll hi = ((c - b + d - a) / delta) + 10;
  ll ans = INF;
  while(lo <= hi){
    ll mid = (lo + hi) / 2;
    ll cur = a + mid * delta;
    if(cur >= c + 1 - b){
      ans = cur;
      hi = mid - 1;
    } else {
      lo = mid + 1;
    }
  }

  cout << ((ans >= 0) ? "Yes" : "No") << '\n';
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int nTest;  cin >> nTest;

  while(nTest--){
    cin >> a >> b >> c >> d;
    solve();
  }

  return 0;
}
