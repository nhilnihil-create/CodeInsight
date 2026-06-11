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
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int64_t n, m;
  cin >> n >> m;

  if (n == 1 && m == 1) { cout << 1 << endl; return 0; }
  if (n == 1) { cout << m-2 << endl; return 0; }
  if (m == 1) { cout << n-2 << endl; return 0; }
  cout << (n-2)*(m-2) << endl;
  return 0;
}