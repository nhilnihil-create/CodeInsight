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

const int MAX_N = 100000;
int N;
ll a[MAX_N];

int main() {
  std::ios::sync_with_stdio(false);std::cin.tie(0);

  cin >> N;
  rep(i, N) cin >> a[i];
  sort(a, a+N);

  ll n = a[N-1];
  ll r = 0;
  if (n%2 == 0) {
      ll mid = n/2;
      ll midist = INFLL;
      for (int i = 0; i < N-1; ++i) {
          ll dist = abs(a[i]-mid);
          if (midist > dist) {
              r = a[i];
              midist = dist;
          }
      }
      cerr << "mid: " << mid << endl;
      cerr << "midist: " << midist << endl;
  } else {
      ll mid = (n-1)/2;
      ll midist = INFLL;
      for (int i = 0; i < N-1; ++i) {
          ll dist;
          if (a[i] > mid) {
              dist = abs(a[i]-(mid+1));
          } else {
              dist = abs(a[i]-mid);
          }
          if (midist > dist) {
              r = a[i];
              midist = dist;
          }
      }
      cerr << "mid: " << mid << endl;
      cerr << "midist: " << midist << endl;
  }

  


  cout << n << ' ' << r << endl;
  return 0;
}
