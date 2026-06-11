#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> v(n);  // subarray from a
  rep(i, n) {
    ll sum = 0;
    for (int j = i; j < n; ++j) {
      sum += a[j];
      v.push_back(sum);
    }
  }

  for (ll i = 50; i >= 0; --i) {
    vector<ll> t;
    ll cnt = 0;
    for (ll value : v) {
      if (value>>i&1) {
        cnt++;
        t.push_back(value);
      }
    }

    if (cnt >= k) {
      v = t;
    }
  }

  ll ans = 0;
  if (v.size() >= k) {
    ans = v[0];
    rep(i, k) ans &= v[i];
  }

  cout << ans << endl;

}