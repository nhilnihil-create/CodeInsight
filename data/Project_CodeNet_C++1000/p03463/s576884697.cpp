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
  int n,a,b;
  cin>>n>>a>>b;
  if(a>b)swap(a,b);
  int rem=(b-a)%2;
  if (rem == 0) {
    cout<<"Alice"<<endl;
  }else{
    cout<<"Borys"<<endl;
  }
  return 0;
}
