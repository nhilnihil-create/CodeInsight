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
  ll k;
  cin>>k;
  vecll a(k);
  for(auto&& e:a)cin>>e;
  ll mn = 2, mx = 2 + a.back() - 1;
  bool ok = a.back() == 2;
  a.pop_back();
  boost::reverse(a);
  for(auto&& e:a) {
    ll nxn = (mn + e - 1) / e * e;
    if (nxn > mx) ok = false;
    ll nxx = mx - mx % e + e - 1;
    mn = nxn;
    mx = nxx;
  }
  if (ok) {
    cout<<mn<<' '<<mx<<endl;
  } else {
    cout<<-1<<endl;
  }
  return 0;
}
