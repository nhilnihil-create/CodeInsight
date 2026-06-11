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

int n, a, b, c;

int dfs(vector<int> &dist, vector<int> &l);

signed main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  cin >> n >> a >> b >> c;
  vector<int> l(n);
  vector<int> dist = {};
  rep(i,n) cin >> l[i];

  cout << dfs(dist, l) << endl;
  return 0;
}



int dfs(vector<int> &dist, vector<int> &l) {

  if (dist.size() == n) {
    int A = 0, B = 0, C = 0;
    int cnt = 0;
    rep(i,n) {
      if (dist[i] == 1) { A += l[i]; cnt++; }
      if (dist[i] == 2) { B += l[i]; cnt++; }
      if (dist[i] == 3) { C += l[i]; cnt++; }
    }

    if (A == 0) return inf;
    if (B == 0) return inf;
    if (C == 0) return inf;

    int ret = 0;
    ret += abs(A-a);
    ret += abs(B-b);
    ret += abs(C-c);
    ret += (cnt-3) * 10;
    return ret;

  }

  int res = inf;
  rep(i,4) {
    dist.push_back(i);
    res = min(res, dfs(dist, l));
    dist.pop_back();
  }

  return res;
}