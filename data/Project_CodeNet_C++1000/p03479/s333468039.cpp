#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  ll x, y;
  cin >> x >> y;
  ll ans = 0;
  while(y >= 2*x) {
    ans++;
    x *= 2;
  }
  ans++;
  cout << ans << endl;
  return 0;
}