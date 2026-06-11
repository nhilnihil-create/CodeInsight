#include <bits/stdc++.h>
#include <boost/range/algorithm.hpp>
#include <boost/range/numeric.hpp>
#include <boost/range/irange.hpp>
#include <boost/range/adaptor/indexed.hpp>

using namespace std;
using namespace boost::adaptors;
using namespace std::string_literals;
using ll = int64_t;
using vecint = vector<int>;
using vecll = vector<ll>;
using boost::irange;

int main()
{
  ll n;
  cin>>n;
  string s;
  cin>>s;
  vecll dp(n, 0);
  constexpr ll MOD = 1000000007;
  dp[0] = 1;
  for(auto&& i:irange(0l,n-1)) {
    ll l = i+1;
    vecll tmp(n, 0);
    if(s[i] == '>') {
      ll sum = 0;
      for(int j=l-1; j>=0; --j) {
        sum += dp[j];
        sum %= MOD;
        tmp[j] = sum;
      }
    } else {
      ll sum = 0;
      for(auto&& j:irange(0l,l+1)) {
        tmp[j] = sum;
        sum += dp[j];
        sum %= MOD;
      }
    }
    swap(dp, tmp);
  }
  ll ans = 0;
  for(auto&& e:dp) {
    ans += e;
    ans %= MOD;
  }
  cout<<ans<<endl;
  return 0;
}
