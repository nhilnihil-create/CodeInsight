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

int main()
{
  std::string s;
  std::cin >> s;
  vector<int> v;
  int left = 0, right = s.size() - 1;
  while (left < right)
  {
    if (s[left] == s[right])
    {
      left++;
      right--;
    }
    else if (s[left] == 'x')
    {
      v.push_back(right);
      left++;
    }
    else if (s[right] == 'x')
    {
      v.push_back(left);
      right--;
    }
    else
    {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << v.size() << endl;

  return 0;
}
