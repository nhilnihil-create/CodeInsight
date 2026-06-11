#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const double EPS = 1e-10;


int main(void) {
  ll X, Y;
  cin >> X >> Y;

  ll ans = 1;
  ll now = X;
  while (now <= Y) {
    ll next = now * 2;
    if (next > Y) break;
    ++ans;
    now = next;
  }

  cout << ans << endl;
  
  return 0;
}