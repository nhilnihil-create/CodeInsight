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
  string s;
  cin>>s;
  int p = 0;
  unordered_map<int, int> dp;
  dp[p] = 0;
  for(char c:s) {
    p ^= 1 << (c - 'a');
    for(auto&& i:irange(0,26)) {
      int q = p ^ (1 << i);
      if (dp.count(q)) {
        if (!dp.count(p)) dp[p] = dp[q] + 1;
        else dp[p] = min(dp[p], dp[q] + 1);
      }
    }
  }
  cout<<max(dp[p], 1)<<endl;
  return 0;
}
