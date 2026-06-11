#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
#define per(i,n) for(int i = n-1; i >= 0; i--)
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<ll> vll;
const long long mod = 1000000007LL;

int main() {
  ll n, m;
  cin >> n >> m;
  vll a(n);
  rep(i,n) cin >> a[i];
  vll v(n);
  ll sum = 0LL;
  rep(i,n) {
    sum += a[i];
    sum %= m;
    v[i] = sum;
  }
  map<ll,ll> mp;
  rep(i,n) mp[v[i]]++;
  mp[0LL]++;
  ll ans = 0LL;
  for(auto p : mp) {
    ll k = p.second;
    ans += k*(k-1)/2;
  }
  cout << ans << endl;
  return 0;
}