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
  long long N;
  scanf("%lld", &N);
  long long K;
  scanf("%lld", &K);
  std::string S;
  std::cin >> S;

  vector<int> v;
  if (S[0] == '0')
    v.push_back(0);
  for (int i = 0; i < S.size();)
  {
    int j = i;
    while (j < S.size() && S[i] == S[j])
      j++;
    v.push_back(j - i);
    i = j;
  }
  if (S[S.size() - 1] == '0')
    v.push_back(0);

  vector<int> num(v.size() + 1, 0);
  for (int i = 0; i < v.size(); ++i)
  {
    num[i + 1] = num[i] + v[i];
  }

  int ans = 0;
  for (int i = 0; i < num.size(); i += 2)
  {
    int j = 2 * K + 1 + i;
    if (j >= num.size())
      j = num.size() - 1;
    ans = max(ans, num[j] - num[i]);
  }
  cout << ans << endl;

  return 0;
}
