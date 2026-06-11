#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <deque>
#include <queue>
#include <array>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <cassert>
#include <utility>
#include <functional>
#include <bitset>

using namespace std;
using lli = long long int;
template<class T, class U> void init_n(vector<T>& v, size_t n, U x) 
{ v = vector<T>(n, x); }
template<class T> void init_n(vector<T>& v, size_t n) { init_n(v, n, T()); }
template<class T> void read_n(vector<T>& v, size_t n, size_t o = 0) 
{ v = vector<T>(n+o); for (lli i=o; i<n+o; ++i) cin >> v[i]; }
template<class T> void read_n(T a[], size_t n, size_t o = 0)
{ for (lli i=o; i<n+o; ++i) cin >> a[i]; }
template<class T> T gabs(const T& x) { return max(x, -x); }
#define abs gabs

lli n, k, a[100001], b[100001];
int main() {
  cin >> n >> k;
  for (lli i=0; i<n; ++i) cin >> a[i] >> b[i];
  
  lli ans = 0;

  for (lli bit = 1; (k == 0 && bit == 1) || bit <= k; bit <<= 1) {
    lli x;
    if (bit == 1) x = k;
    else if (bit & k) {
      x = (k & (~bit)) | (bit-1);
    } else {
      continue;
    }
    // cerr << bitset<31>(x) << '\n';
    lli scr = 0;
    for (lli i=0; i<n; ++i) {
      if ((a[i] | x) == x) scr += b[i];
    }
    ans = max(ans, scr);
  }

  cout << ans << '\n';
  return 0;
}
