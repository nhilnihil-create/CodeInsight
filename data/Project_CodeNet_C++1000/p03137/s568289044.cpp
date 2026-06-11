#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> x(m);
  rep(i,m) cin >> x[i];
  ll ans = 0;
  if (n >= m) {
    cout << ans << endl;
    return 0;
  } else {
    sort(x.begin(), x.end());
    vector<ll> dis(m-1);
    rep(i,m-1) {
      dis[i] = x[i+1] - x[i];
    }
    sort(dis.begin(), dis.end());

    rep(i,m-n) {
      ans += dis[i];
    }
    cout << ans << endl;
  }
  return 0;
}