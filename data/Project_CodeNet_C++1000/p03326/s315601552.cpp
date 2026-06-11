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
  vll x(n), y(n), z(n);
  rep(i,n) cin >> x[i] >> y[i] >> z[i];
  ll ans = 0LL;
  rep(i,(1<<3)) {
    vll v;
    rep(j,n) {
      ll tmp = 0LL;
      if(i & 1) tmp += x[j];
      else tmp -= x[j];
      if(i>>1 & 1) tmp += y[j];
      else tmp -= y[j];
      if(i>>2 & 1) tmp += z[j];
      else tmp -= z[j];
      v.push_back(tmp);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    ll sum = 0LL;
    rep(j,m) sum += v[j];
    ans = max(ans,sum); 
  }
  cout << ans << endl;
  return 0;
}