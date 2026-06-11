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

#define rep(i,n) for(int i=0; i<(int)(n); i++)

const int mod = 1000000007;

bool isIn(long xl, long yl, long xr, long yr, P target) {
  bool res = true;
  res = res && xr >= target.first;
  res = res && yr >= target.second;
  res = res && xl <= target.first;
  res = res && yl <= target.second;
  return res;
}

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;

  vector<P> points(n);
  vector<long> xs(n);
  vector<long> ys(n);

  rep(i, n) {
    long x, y;
    cin >> x >> y;
    points[i] = {x, y};
    xs[i] = x;
    ys[i] = y;
  }

  sortv(xs);
  sortv(ys);

  ll res = INF*INF*4;

  rep(il, n-1) rep(jl, n-1) {
    for(int i = il+1; i < n; i++) {
      for(int j = jl+1; j < n; j++) {
        ll size = (xs[i] - xs[il]) * (ys[j] - ys[jl]);
        if (size == 0) continue;
        int tmp = 0;
        rep(k, n) {
          if (isIn(xs[il], ys[jl], xs[i], ys[j], points[k])) tmp++;
        }
        if (tmp >= m) {
          res = min(res, size);
        }
      } 
    }
  }

  cout << res << endl;
}
