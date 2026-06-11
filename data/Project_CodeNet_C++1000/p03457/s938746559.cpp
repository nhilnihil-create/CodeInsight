#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#include <regex>
#define rep(i,n) for(int i = 0; i < n; i++)
#define reps(i,j,n) for(int i = j; i < n; i++)
#define rrep(i,j,n) for(int i = j-1; i >= n; i--)
#define prec(n) fixed << setprecision(n)
#define print_array(v) rep(__k, v.size()) { cout << v[__k]; if(__k != v.size()-1) cout << " "; else cout << endl; }
#define YesorNo(a) printf(a?"Yes\n":"No\n")
#define fi first
#define se second
using namespace std;

int inf = 2147483647;
int64_t inf64 = 9223372036854775807;
int mod = 1e+7;

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> t(n);
  vector<int> x(n);
  vector<int> y(n);
  rep(i,n) cin >> t[i] >> x[i] >> y[i];

  bool res = true;
  rep(i,n) {
    int xy = x[i] + y[i];
    if(t[i] < xy) res = false;
    if(t[i]%2 != xy%2) res = false;
  }
  reps(i,1,n) {
    int tdiff = t[i] - t[i-1];
    int xydiff = abs(x[i] - x[i-1]) + abs(y[i] - y[i-1]);
    if(tdiff < xydiff) res = false;
  }
  YesorNo(res);
  return 0;
}