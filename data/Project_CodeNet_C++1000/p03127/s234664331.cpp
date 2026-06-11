#include <bits/stdc++.h>
#include <boost/integer/common_factor_rt.hpp>
using namespace std;
using ll=long long;

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  for(int i=0;i<n;i++){
    cin >> a.at(i);
  }
  ll ans=boost::integer::gcd_range(a.begin(), a.end()).first;
  cout << ans << endl;
}

