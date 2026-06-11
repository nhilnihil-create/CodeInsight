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
#define _size(X) (int)((X).size())
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

const int MAX_Q = 100;
int Q;
ll A[MAX_Q], B[MAX_Q];

int main() {
  std::ios::sync_with_stdio(false);std::cin.tie(0);

  cin >> Q;
  rep(i, Q) cin >> A[i] >> B[i];

  for (int q = 0; q < Q; ++q) {
      ll a = A[q], b = B[q];
      ll score = a*b;

      if (score == 1 || score == 2) {
          cout << 0 << endl;
          continue;
      }

      ll lb = 1, ub = 1e18, mid;
      while ((ub-lb)>1) {
          mid = (ub+lb)/2;
          ll t1 = (score-1)/mid;
          ll t2 = (score-1)/(mid+1);
          if (t1 > t2 && t2+1 >= mid) {
              lb = mid;
          } else {
              ub = mid;
          }
      }

      ll t1 = (score-1)/lb;
      ll t2 = (score-1)/(lb+1);
      if (lb == t2+1 && (t1-t2) == 1) {
          cout << 2*(lb-1) + 1 - ((a <= lb || b <= lb) ? 1 : 0) << endl;
      } else {
          cout << 2*lb - ((a <= lb || b <= lb) ? 1 :0) << endl;
      }
  }

  return 0;
}
