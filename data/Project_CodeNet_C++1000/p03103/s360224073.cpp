#include<bits/stdc++.h>
using namespace std;
using ll= long long;
#define rep(i,n) for (ll i=0; i<(n); i++)

int main() {
  ll n, m;
  cin >> n >> m;
  vector<pair<ll,ll>> ab(n);
  rep(i,n) cin >> ab[i].first >> ab[i].second;
  
  sort(ab.begin(), ab.end());
  ll cnt = 0, ans = 0;
  
  rep(i,n) {
    if (cnt < m && cnt + ab[i].second <= m) {
      cnt += ab[i].second;
      ans += ab[i].first * ab[i].second;
    }
    else if (cnt < m && ans + ab[i].second >= m) {
      ans += ab[i].first * (m - cnt);
      while (cnt < m) cnt++;
    }
  }
  
  cout << ans << endl;
}