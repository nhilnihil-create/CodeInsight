#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> h(n);
  rep(i,n) cin >> h[i];
  sort(h.begin(), h.end());
  ll ans = 1e9+7;
  rep(i,n-k+1) {
    ll tmp = h[i+k-1] - h[i];
    ans = min(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}