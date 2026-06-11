#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, a, b) for (ll i = (a); i < (b); i++)
typedef uint64_t ull;
typedef int64_t ll;
typedef std::pair<ll, ll> PLL;

using namespace std;

signed main() {
  ll N;
  cin >> N;
  vector<ll> d(N);
  rep(i,N) {
    cin >> d[i];
  }
  sort(begin(d), end(d));

  // 上から順に左右に振り分けていく
  vector<ll> v;
  rep(i,d.size()) {
    if (i%2==0) {
      v.push_back(d[i]);
    } else {
      v.push_back(24-d[i]);
    }
  }
  v.push_back(0);
  v.push_back(24);

  sort(begin(v), end(v));
  //cout << "v: ";
  //rep(i,v.size()) {
  //  cout << v[i] << " ";
  //}
  //cout << endl;

  ll ans = 3333;
  rep(i, N+1) {
    ans = min(ans, v[i+1]-v[i]);
  }
  cout << ans << endl;

  return 0;
}
