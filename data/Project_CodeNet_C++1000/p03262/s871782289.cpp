#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  int n, x; cin >> n >> x;

  vector<int> co(n+1);
  rep(i,n) {
    int y; cin >> y;
    co[i] = abs(x-y);
  }
  co[n] = co[n-1];
  int ans;
  if (co[0] == 0) ans = co[1];
  else ans = co[0];
  rep(i,n) {
    if (co[i] == 0) continue;
    ans = __gcd(ans,co[i]);
  }
  cout << ans << endl;
  return 0;
}