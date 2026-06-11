#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <climits>
#include <random>
#include <iomanip>

using namespace std;
using P = pair<long, long>;

typedef long long int ll;

#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

#define fillInt(xs, x)        \
  for (int i = 0; i < (x); i++) \
    scanf("%d", &xs[i]);
#define fillLong(xs, x)       \
  for (int i = 0; i < (x); i++) \
    scanf("%ld", &xs[i]);
#define fillString(xs, x)       \
  for (int i = 0; i < (x); i++) \
    cin >> xs[i];
#define sortv(xs) sort(xs.begin(), xs.end())
#define sortvinv(xs) sort(xs.begin(), xs.end(), std::greater<long>())
#define lbv(xs, x) lower_bound(xs.begin(), xs.end(), x) - xs.begin()
#define ubv(xs, x) upper_bound(xs.begin(), xs.end(), x) - xs.begin()
#define bs(xs, x) binary_search(xs.begin(), xs.end(), x)
#define index_of(as, x) \
  distance(as.begin(), lower_bound(as.begin(), as.end(), x))

#define rep(i,n) for(auto i=0; i<(n); i++)

const int mod = 1000000007;


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  vector<long> a(n);
  fillLong(a, n);

  vector<long> b(n+1);
  b[0] = 0;
  rep(i, n) {
    b[i+1] = b[i] + a[i];
  }

  vector<long> c;

  rep(i, n) {
    for(int j = i+1; j<n+1; j++) {
      c.push_back(b[j] - b[i]);
    }
  }

  sortv(c);

  long res = 0;

  for(int i = 50; i >= 0; i--) {
    long l = lbv(c, 1L<<i);
    if (c.size() - l >= k) {
      c.erase(c.begin(), c.begin() + l);
      res += (1L<<i);
    }
    rep(j, c.size()) {
      c[j] &= ~(1L<<i);
    }
    sortv(c);
  }

  cout << res << endl;
}
