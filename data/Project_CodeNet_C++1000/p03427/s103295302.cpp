#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(int)(n); i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n; cin >> n;
  int ans = 0;
  while (n > 0) {
    int x = n % 10;
    n /= 10;
    if (n > 0) ans += 9;
    else ans += x;
    if (x != 9) n--;
  }
  cout << ans << endl;
  return 0;
}