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
#define MOD 1e+7
#define inf 1e9
#define fi first
#define se second
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  string s;
  cin >> n >> s;
  vector<int> w(n+1, 0);
  vector<int> e(n+1, 0);
  rep(i,n) {
    int W = 0, E = 0;
    if(s[i] == 'W') W++;
    if(s[i] == 'E') E++;
    w[i+1] = w[i] + W;
    e[i+1] = e[i] + E;
  }

  int res = inf;
  rep(i,n+1) {
    int cur = 0;
    cur += e[n] - e[i];
    cur += w[i];
    res = min(res, cur);
  }
  cout << res << endl;
  return 0;
}
//templete by private_yusuke