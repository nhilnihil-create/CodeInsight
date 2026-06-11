#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;

using ll = long long;
using ld = long double;
const int INF = 1e9;
const double EPS = 1e-9;
const ll MOD = 1e9 + 7;

bool betemp(string sleft, string sright, int left, int right)
{
  if (sleft == sright)
    return (right - left) % 2 == 1;
  else
    return (right - left) % 2 == 0;
}

int main()
{
  int N;
  cin >> N;

  string vac = "Vacant";
  string sl, sr, s;
  int l = 0, r = N - 1;
  cout << l << endl;
  cin >> sl;
  if (sl == vac)
    return 0;
  cout << r << endl;
  cin >> sr;
  if (sr == vac)
    return 0;

  while (r - l > 1)
  {
    int m = (l + r) / 2;
    cout << m << endl;
    cin >> s;
    if (betemp(sl, s, l, m))
      sr = s, r = m;
    else
      sl = s, l = m;
  }

  return 0;
}
