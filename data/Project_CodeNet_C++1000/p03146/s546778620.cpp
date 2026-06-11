#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll f(ll n) {
  return n % 2 == 0 ? n / 2 : 3 * n + 1;
}

int main(void) {
  ll s;
  cin >> s;

  map<ll, int> a;
  a[s]++;
  ll ans = 1;
  ll old = s;
  while (true) {
    ll next = f(old);
    a[next]++;
    ans++;
    if (a[next] == 2) {
      break;
    }
    old = next;
  }
  
  cout << ans << endl;
  
  return 0;
}