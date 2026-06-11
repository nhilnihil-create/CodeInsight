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
#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i,j,n) for(int i = j; i < n; i++)
#define RFOR(i,j,n) for(int i = j-1; i >= n; i--)
#define PREC(n) fixed << setprecision(n)
#define print_array(v) REP(__k, v.size()) { cout << v[__k]; if(__k != v.size()-1) cout << " "; else cout << endl; }
#define YesorNo(a) printf(a?"Yes\n":"No\n")
#define _LIBCPP_DEBUG 0
using namespace std;
int64_t MOD = 1000000007;
int inf = 1e9;

int f(int n) {
  if(n % 10 == 0) { return n; }
  else { return n + (10 - n % 10); }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  vector<int> vec(5);
  REP(i,5) cin >> vec[i];
  int maxi = -1;
  REP(i,5) {
    int a = vec[i];
    if(f(a) - a > maxi) maxi = f(a) - a;
    vec[i] = f(a);
  }
  cout << accumulate(vec.begin(), vec.end(),0) - maxi << endl;
  return 0;
}
//templete by private_yusuke