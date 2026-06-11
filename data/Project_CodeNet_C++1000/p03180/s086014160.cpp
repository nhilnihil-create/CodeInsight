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
  vector<vecll> a(n, vecll(n));
  for(auto&& l:a)for(auto&& e:l)cin>>e;
  vecll dp(1<<n);
  for(auto&& i:irange(0,1<<n)) {
    ll sum = 0;
    for(auto&& j:irange(0l,n)) {
      if((i>>j)&1) {
        for(auto&& k:irange(0l,j)) {
          if((i>>k)&1) {
            sum += a[j][k];
          }
        }
      }
    }
    dp[i] = sum;
  }
  for(auto&& i:irange(0,1<<n)) {
    for (int U = (1 << n) - 1; U >= 0; --U) {
      U &= i;
      dp[i] = max(dp[i], dp[U] + dp[i^U]);
    }
  }
  cout<<dp.back()<<endl;
  return 0;
}
