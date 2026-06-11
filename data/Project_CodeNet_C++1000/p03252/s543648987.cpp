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
  std::string S;
  std::cin >> S;
  std::string T;
  std::cin >> T;
  vector<int> a[26], b[26];
  for (int i = 0; i < S.size(); ++i)
  {
    a[S[i] - 'a'].push_back(i);
    b[T[i] - 'a'].push_back(i);
  }
  int cnt = 0;
  int x = 0, y = 0;
  for (int i = 0; i < 26; ++i)
  {
    if (a[i].size())
      x++;
    for (int j = 0; j < 26; ++j)
    {
      if (a[i].size() && b[j].size() && a[i] == b[j])
        cnt++;
      if (i == 0 && b[j].size())
        y++;
    }
  }
  if (x == y && cnt == x)
    cout << YES << endl;
  else
    cout << NO << endl;

  return 0;
}
