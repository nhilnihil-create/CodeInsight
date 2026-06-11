#include <bits/stdc++.h>
#include <boost/integer/common_factor_rt.hpp>
using namespace std;
using ll=long long;
const int MOD=1000000007;

int main() {
  ll n,a,b,c,d,e;
  cin >> n;
  cin >> a;
  cin >> b;
  cin >> c;
  cin >> d;
  cin >> e;
  vector<ll> v={a,b,c,d,e};
  sort(v.begin(),v.end());
  ll ans=(n-1)/v.at(0)+5;
  cout << ans << endl;
}