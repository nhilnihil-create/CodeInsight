#include <bits/stdc++.h>
#define IOS                                                                    \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
ll bpow(ll b, ll p, ll m = 1000000007LL) {
  ll rt = 1;
  for (; p; p >>= 1, b = b * b % m)
    if (p & 1)
      rt = rt * b % m;
  return rt;
}
ll a[100005];
ll psum[100005];
int main() {
  IOS;
  int n, k;
  cin >> n >> k;
  vector<ll> v;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    psum[i] = psum[i - 1] + a[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      v.pb(psum[j] - psum[i - 1]);
    }
  }
  ll ans = 0;
  for (int i = 60; i >= 0; i--) {
    vector<ll> tmp;
    int cnt = 0;
    for (ll x : v) {
      if ((1LL << i) & x)
        cnt++, tmp.pb(x);
    }
    if (cnt >= k)
      v.clear(), v = tmp, ans |= (1LL << i);
  }
  cout << ans << endl;
}
