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

vector<ll> enum_div(ll n) {
  vector<ll> ret;
  for(ll i = 2LL; i*i <= n; i++) {
    if(n%i == 0LL) {
      ret.push_back(i);
      if(i != 1LL && i*i != n) {
        ret.push_back(n/i);
      }
    }
  }
  ret.push_back(n);
  sort(ret.begin(), ret.end());
  return ret;
}

int main() {
  ll n, m;
  cin >> n >> m;
  vll v = enum_div(m);
  ll ans = 1LL;
  rep(i,v.size()) if(m/v[i]>=n) ans = max(ans,v[i]);
  cout << ans << endl;
  return 0;
}