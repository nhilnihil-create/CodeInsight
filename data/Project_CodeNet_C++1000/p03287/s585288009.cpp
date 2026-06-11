#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
const int INF = 1000000000;
const int MOD = 1000000007;

ll gcd(ll a, ll b) { return b?gcd(b,a%b):a;}
ll lcm(ll a, ll b) { return a/gcd(a,b)*b;}

int main() {
  ll n, m;
  cin >> n >> m;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  vector<ll> cumsum(n+1, 0);
  rep(i, n){
    cumsum[i+1] = cumsum[i] + a[i];
  }

  map<ll, ll> mp;
  rep(i, n+1){
    mp[cumsum[i] % m]++;
  }

  ll ans = 0;
  for(auto itr : mp){
    ans += itr.second * (itr.second - 1) / 2;
  }

  cout << ans << endl;
  return 0;
}
