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
  std::string ABCD;
  std::cin >> ABCD;
  for (int bit = 0; bit < (1 << 3); ++bit)
  {
    int t = ABCD[0] - '0';
    for (int i = 0; i < 3; ++i)
    {
      if (bit & (1 << i))
        t += ABCD[i + 1] - '0';
      else
        t -= ABCD[i + 1] - '0';
    }
    if (t == 7)
    {
      cout << ABCD[0];
      for (int i = 0; i < 3; ++i)
      {
        if (bit & (1 << i))
          cout << '+';
        else
          cout << '-';
        cout << ABCD[i + 1];
      }
      cout << "=7" << endl;
      break;
    }
  }

  return 0;
}
