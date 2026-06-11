#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define contains(v, t) (find(v.begin(), v.end(), t) != v.end())
#define MOD 1000000007
typedef long long ll;
typedef unsigned long long ull;

int main() {
  int n;
  cin >> n;
  vector<ll> v(n+1);
  v[0] = 0;

  // 累積和
  rep(i, n) {
    ll t;
    cin >> t;
    v[i+1] = v[i] + t;
  }

  map<ll, ll> m;
  rep(i, n + 1) {
    m[v[i]]++;
  }

  ll ans = 0;
  for(auto it: m) {
    ans += it.second * (it.second - 1) / 2;
  }

  cout << ans;
}
