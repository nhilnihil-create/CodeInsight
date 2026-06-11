#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(void) {
  int N;
  cin >> N;
  ll ans = 0;
  rep(i, N) {
    ll a;
    cin >> a;
    ans += a - 1;
  }

  cout << ans << endl;
  
  return 0;
}