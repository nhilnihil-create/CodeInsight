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
const int MOD = 1e9 + 7;

int main()
{
  long long N;
  scanf("%lld", &N);
  std::vector<std::string> S(N);
  map<char, ll> mp;
  for (int i = 0; i < N; i++)
  {
    std::cin >> S[i];
    mp[S[i][0]]++;
  }
  vector<char> t = {'M', 'A', 'R', 'C', 'H'};
  ll ans = 0;
  for (int i = 0; i < t.size(); ++i)
  {
    for (int j = i + 1; j < t.size(); ++j)
    {
      for (int k = j + 1; k < t.size(); ++k)
        ans += mp[t[i]] * mp[t[j]] * mp[t[k]];
    }
  }
  cout << ans << endl;

  return 0;
}
