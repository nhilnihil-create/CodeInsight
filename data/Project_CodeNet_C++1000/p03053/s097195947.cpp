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
constexpr int mod = 1e+7;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

signed main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int h, w;
  cin >> h >> w;
  vector<string> grid(h);
  rep(i,h) cin >> grid[i];

  queue<pair<int, int>> que;
  vector<vector<int>> dist(h, vector<int> (w, -1));
  rep(sh,h) {
    rep(sw, w) {
      if(grid[sh][sw] == '#') {
        dist[sh][sw] = 0;
        que.push({sh, sw});
      }
    }
  }

  while(!que.empty()) {
    int vh = que.front().fi;
    int vw = que.front().se;
    que.pop();

    rep(dir, 4) {
      int nvh = vh + dy[dir];
      int nvw = vw + dx[dir];

      if(nvh < 0) continue;
      if(nvw < 0) continue;
      if(nvh >= h) continue;
      if(nvw >= w) continue;
      if(dist[nvh][nvw] != -1) continue;
      if(grid[nvh][nvw] == '#') continue;

      dist[nvh][nvw] = dist[vh][vw]+1;
      que.push({nvh, nvw});
    }
  }

  int res = -1;
  rep(gh,h) rep(gw,w) res = max(res, dist[gh][gw]);
  cout << res << endl;
  return 0;
}