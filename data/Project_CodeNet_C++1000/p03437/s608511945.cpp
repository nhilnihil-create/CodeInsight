#include <iostream>
#define rep(i, n) for(int i = 0; i < (n); ++i)
typedef long long ll;
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll a, b; cin >> a >> b;
  ll ans = -1;
  if(a%b != 0) ans = a;

  cout << ans << '\n';
  return 0;
}
