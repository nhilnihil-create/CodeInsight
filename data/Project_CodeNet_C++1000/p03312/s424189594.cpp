#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <utility>

using namespace std;
using lli = long long int;
// #define DEBUG
#ifdef DEBUG
#define debug(var) cout << (#var) << ": " << (var) << endl;
template<class T> void dump_array_impl(const T& a) {
  bool first = true;
  for (auto&& x : a) {
    if (!first) { cout << ", "; first = false; }
    cout << x;
  }
}
#define debug_array(a) cout<<(#a)<<": ";dump_array_impl(a);cout<<endl
#else
#define debug(var) {}
#define debug_array(a) {}
#endif
template<class T> void read_n(vector<T>& v, size_t n) {
  v = vector<T>(n);
  for (lli i=0; i<n; ++i) cin >> v[i];
}
/*
template<class T> const T& gabs(const T& x) { return max(x, -x); }
#define abs gabs
*/
lli n;
vector<lli> v;
int main() {
  cin >> n;
  read_n(v, n);
  lli p=v[0], q=v[1], r=v[2], s=accumulate(begin(v)+3, end(v), 0ll);
  lli x=1, y=2, z=3;
  lli ans=1e17;
  while (y <= v.size()-2) {
    while (x+1<y && abs(q-p) > abs(q-v[x] - (p+v[x]))) {
      p+=v[x]; q-=v[x]; ++x; 
    }
    while (z+1<n && abs(s-r) > abs(s-v[z] - (r+v[z]))) {
      r+=v[z]; s-=v[z]; ++z; 
    }

    // printf("x:%lld, y:%lld, z:%lld %lld %lld %lld %lld\n", x, y, z,p,q,r,s);

    lli cur = max(max(p,q), max(r,s)) - min(min(p,q), min(r,s));
    ans = min(ans, cur);

    q+=v[y]; r-=v[y]; ++y;
    if (y == z) {
      r+=v[z]; s-=v[z]; ++z; 
    }
  }
  cout << ans << endl;
  return 0;
}
