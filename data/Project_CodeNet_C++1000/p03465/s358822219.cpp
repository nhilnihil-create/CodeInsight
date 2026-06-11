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
  int n;
  cin>>n;
  vecint a(n);
  for(auto&& e:a)cin>>e;
  bitset<4000001> dp;
  dp.set(0, true);
  int sum=0;
  for(auto&& e:a){
    dp |= dp<<e;
    sum += e;
  }
  for(int i=(sum+1)/2;i<=sum;++i) {
    if(dp.test(i)) {
      cout<<i<<endl;
      break;
    }
  }
  return 0;
}
