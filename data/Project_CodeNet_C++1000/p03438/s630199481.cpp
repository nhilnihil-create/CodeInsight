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

const string YES = "Yes";
const string NO = "No";

int main()
{
  long long N;
  scanf("%lld", &N);
  std::vector<long long> a(N);
  for (int i = 0; i < N; i++)
  {
    scanf("%lld", &a[i]);
  }
  std::vector<long long> b(N);
  for (int i = 0; i < N; i++)
  {
    scanf("%lld", &b[i]);
  }
  ll cnt = 0;
  for (int i = 0; i < N; ++i)
  {
    if (a[i] < b[i])
    {
      cnt += (b[i] - a[i]) / 2;
    }
    else
    {
      cnt -= a[i] - b[i];
    }
  }
  cout << (cnt >= 0 ? YES : NO) << endl;

  return 0;
}
