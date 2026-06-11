#include <bits/stdc++.h>
using namespace std;
using ll=long long;
template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
using vll = V<ll>;
using vvll = V<vll>;

const ll MOD = (ll)1e9 + 7;
const ll INF = (ll)1e18;

int main(){
  ll n; cin >> n;
  V<string> s(n); for(int i=0; i<n; i++) cin >> s.at(i);

  ll ans = 0; bool is_rev = true;
  for (ll b=0; b<n; b++) {
    is_rev = true;
    for (ll i=0; i<n; i++) {
      for (ll j=0; j<n; j++) {
        if (s.at((n + j-b) % n).at(i) != s.at((n + i-b) % n).at(j)) {
          is_rev = false;
          break;
        }
      }
      if (!is_rev) break;
    }
    if (is_rev) ans += 1;
  }
  cout << ans * n << endl;
  return 0;
}
