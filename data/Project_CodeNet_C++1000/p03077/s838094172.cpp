#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  ll n;
  cin >> n;
  vector<ll> v(5);
  rep(i, v.size()) {
    cin >> v[i];
  }

  ll minMove = v[0];
  for (int i = 1; i < v.size(); ++i) minMove = min(minMove, v[i]);
  ll ans = ((n + minMove - 1) / minMove) + 4;  

  cout << ans << endl;
  
  return 0;
}