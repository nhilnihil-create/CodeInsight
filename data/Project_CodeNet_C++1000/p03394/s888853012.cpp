#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <utility>
#include <vector>
#include <complex>
#include <valarray>
#include <fstream>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <numeric>
#include <climits>
#include <random>

#define _overload(a, b, c, d, ...) d
#define _rep1(X, A, Y) for (int (X) = (A);(X) <= (Y);++(X))
#define _rep2(X, Y) for (int (X) = 0;(X) < (Y);++(X))
#define rep(...) _overload(__VA_ARGS__, _rep1, _rep2)(__VA_ARGS__)
#define rrep(X,Y) for (int (X) = Y-1;(X) >= 0;--(X))
#define all(X) (X).begin(),(X).end()
#define len(X) ((int)(X).size())
#define mod(n, m) (((n)%(m)+(m))%m)
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
const int INFINT = 1 << 30;                          // 1.07x10^ 9
const ll INFLL = 1LL << 60;                          // 1.15x10^18
const double EPS = 1e-10;
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

int N;
vector<int> ans;

int main() {
  std::ios::sync_with_stdio(false);std::cin.tie(0);

  cin >> N;

  if (N == 3) {
      cout << 2 << ' ' << 3 << ' ' << 25 << endl;
      return 0;
  }

  ans.push_back(2);
  ans.push_back(3);
  ans.push_back(8);
  ans.push_back(9);
  int count = 4;
  if (count < N) {
      ans.push_back(10);
      ++count;
  }
  if (count < N) {
      ans.push_back(12);
      ++count;
  }

  for (int i = 16; i <= 30000; i += 2) {
      if (count == N) break;
      ans.push_back(i);
      ++count;
  }

  for (int i = 12; i <= 30000; i += 3) {
      if (count == N) break;
      if (i%2 == 0) continue;
      ans.push_back(i);
      ++count;
  }

  if (count < N) {
      if (N == 19998) {
          ans.push_back(6);
      } else if (N == 19999) {
          ans.push_back(4);
          ans.push_back(14);
      } else {
          ans.push_back(4);
          ans.push_back(6);
          ans.push_back(14);
      }
  }

  
  ll sum = 0;
  for (int i = 0; i < len(ans); ++i) {
      sum += ans[i];
  }

  switch (sum%6) {
      case 1:
          ans[3] = 14;
          break;
      case 2:
          ans[2] = 6;
          break;
      case 3:
          ans[3] = 6;
          break;
      case 4:
          ans[2] = 4;
          break;
      case 5:
          ans[3] = 4;
          break;
  }

  sum = 0;
  for (int i = 0; i < len(ans); ++i) {
      sum += ans[i];
  }

  for (int i = 0; i < len(ans); ++i) {
      cout << ans[i] << (i+1 == len(ans) ? '\n' : ' ');
  }

  return 0;

}

