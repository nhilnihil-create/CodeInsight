#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pr = pair<ll, ll>;
#define rep(n, i) for(ll i = 0; i < n; ++i)

void solve(void){
  ll n, m; cin >> n >> m;
  vector<pr> vec;
  rep(n, i) {
    ll ta, tb;
    cin >> ta >> tb;
    vec.emplace_back(make_pair(ta, tb));
  }

  sort(vec.begin(), vec.end());

  ll res = 0;
  ll cnt = 0;
  rep(n, i) {
    if (m - cnt > vec[i].second) {
      res += (vec[i].first * vec[i].second );
      cnt += vec[i].second;
    } else {
      res += (vec[i].first * (m - cnt));
      break;
    }
  }

  cout << res << endl;
  return;
}

int main(void) {
  solve();
  return 0;
}