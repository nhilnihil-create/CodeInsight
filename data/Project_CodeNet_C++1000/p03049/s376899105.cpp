#pragma GCC target("avx")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
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
#define endl "\n"
using namespace std;

constexpr int inf = 2147483647;
constexpr int64_t inf64 = 9223372036854775807;
constexpr int mod = 1e9+7;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, cnt_ab = 0, last_a = 0, begin_b = 0, banda = 0;
  cin >> n;

  rep(i,n) {
    string s;
    cin >> s;
    rep(i,s.size()-1) if(s.substr(i,2) == "AB") cnt_ab++;
    if(s[0] == 'B') begin_b++;
    if(s[s.size()-1] == 'A') last_a++;
    if(s[0] == 'B' && s[s.size()-1] == 'A') banda++, begin_b--, last_a--;
  }

  if(banda == 0)cout << cnt_ab + min(begin_b, last_a) << endl;
  else if(begin_b + last_a > 0) cout << cnt_ab + banda + min(begin_b, last_a) << endl;
  else if(begin_b + last_a == 0) cout << cnt_ab + banda - 1 << endl;
  return 0;
}