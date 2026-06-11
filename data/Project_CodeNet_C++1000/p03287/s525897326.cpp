#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long double PI = acos(-1);
#define chmin(i, j) i = min(i, j);
#define chmax(i, j) i = max(i, j);
#define rep(i, n) for(int i=0;i<n;i++)
ll MOD = 1000000007;
ll fact(ll m) {
  if(m == 0 || m == 1) return 1LL;
  else return (m * fact(m-1LL)) % MOD;
}
bool custom(pair<ll, ll> a, pair<ll, ll> b) {
  if(a.first == b.first) return (a.second > b.second);
  else return a.first < b.first;
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  for(int i=0;i<n;i++) cin >> a[i];
  map<int, ll> cnt;
  ll ans = 0;
  vector<ll> total(n);
  for(int i=0;i<n;i++) {
    if(i == 0) total[i] = a[i];
    else total[i] = total[i-1] + a[i];
    cnt[total[i]%m]++;
  }
  for(auto it=cnt.begin();it!=cnt.end();it++) {
    ll a = it->second;
    if(it->first == 0) ans += a;
    ans += a * (a-1) / 2;
  }
  cout << ans << endl;
}
