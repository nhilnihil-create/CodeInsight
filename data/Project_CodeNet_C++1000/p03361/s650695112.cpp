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
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int h, w;
  cin >> h >> w;
  vector<string> grid(h);
  rep(i,h) cin >> grid[i];

  rep(i,h) {
    rep(j,w) {
      if(grid[i][j] == '.') continue;

      bool flag = false;
      rep(dir, 4) {
        int ni = i + dy[dir];
        int nj = j + dx[dir];

        if(ni < 0) continue;
        if(nj < 0) continue;
        if(ni >= h) continue;
        if(nj >= w) continue;

        if(grid[ni][nj] == '#') flag = true;
      }
      if(!flag) { cout << "No" << endl; return 0; }
    }
  }

  cout << "Yes" << endl;
  return 0;
}