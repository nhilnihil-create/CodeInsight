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

  string s;
  cin >> s;

  int cnt1 = 0;
  rep(i,s.size()) {
    if(i % 2 == 0 && s[i] == '1') cnt1++;
    if(i % 2 == 1 && s[i] == '0') cnt1++;
  }
  int cnt2 = 0;
  rep(i,s.size()) {
    if(i % 2 == 0 && s[i] == '0') cnt2++;
    if(i % 2 == 1 && s[i] == '1') cnt2++;
  }
  cout << min(cnt1, cnt2) << endl;
  return 0;
}