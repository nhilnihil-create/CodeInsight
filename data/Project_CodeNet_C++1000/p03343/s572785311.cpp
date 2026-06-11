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

bool ok(const vecint& a, int k, int q, int lowest, int highest) {
  int num = 0;
  int len = 0;
  int cnt = 0;
  for(auto&& e:a) {
    if (e < lowest) {
      num += min(cnt, max(0, len-k+1));
      len = 0;
      cnt = 0;
    }
    else {
      ++len;
      if (e <= highest) ++cnt;
    }
  }
  num += min(cnt, max(0, len-k+1));
  return num >= q;
}

int main()
{
  int n,k,q;
  cin>>n>>k>>q;
  vecint a(n);
  for(auto&& e:a) cin>>e;
  set<int> sa;
  for(auto&& e:a) sa.insert(e);
  int ans = 1e9;
  for (auto&& e:sa) {
    int lo = -1;
    int hi = 1e9;
    while (hi-lo > 1) {
      int mid = (hi+lo)/2;
      if (ok(a,k,q,e,e+mid)) {
        hi = mid;
      } else {
        lo = mid;
      }
    }
    ans = min(ans, hi);
  }
  cout<<ans<<endl;
  return 0;
}
