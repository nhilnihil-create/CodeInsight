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

#define fillInt(xs)        \
  for (int i = 0; i < (xs).size(); i++) \
    scanf("%d", &xs[i]);
#define fillLong(xs)       \
  for (int i = 0; i < (xs).size(); i++) \
    scanf("%ld", &xs[i]);
#define fillDouble(xs)       \
  for (int i = 0; i < (xs).size(); i++) \
    scanf("%lf", &xs[i]);
#define fillString(xs)       \
  for (int i = 0; i < (xs).size(); i++) \
    cin >> xs[i];
#define sortv(xs) sort(xs.begin(), xs.end())
#define sortvinv(xs) sort(xs.begin(), xs.end(), std::greater<long>())
#define lbv(xs, x) lower_bound(xs.begin(), xs.end(), x) - xs.begin()
#define ubv(xs, x) upper_bound(xs.begin(), xs.end(), x) - xs.begin()
#define bs(xs, x) binary_search(xs.begin(), xs.end(), x)
#define index_of(as, x) \
  distance(as.begin(), lower_bound(as.begin(), as.end(), x))
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define concat(xs, ys) (xs).insert((xs).end(), (ys).begin(), (ys).end())

const int mod = 1000000007;

struct td {
  char t;
  char d;
};

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;

  string s;
  cin >> s;

  vector<td> magics;

  rep(i, q) {
    char t, d;
    cin >> t >> d;
    magics.push_back(td{t, d});
  }


int res = n;
 {
   int ub = n;
   int lb = -1;

  while(ub - lb > 1) {
    int next = (ub+lb)/2;
    char now = s[next];
    int nowi = next;
    int i = 0;
    while(i < q) {
      while(i < q && magics[i].t != now) {
        i++;
      }
      if (i == q) {
        break;
      }
      nowi = nowi + (magics[i].d == 'L' ? -1: 1);
      i++;
      if (nowi < 0 || nowi > n-1) {
        break;
      }
      now = s[nowi];
    }
    if (nowi < 0) {
      lb = next;
    } else {
      ub = next;
    }
  }
  res -= (lb+1);
 }

 {
   int ub = n;
   int lb = -1;

  while(ub - lb > 1) {
    int next = (ub+lb)/2;
    char now = s[next];
    int nowi = next;
    int i = 0;
    while(i < q) {
      while(i < q && magics[i].t != now) {
        i++;
      }
      if (i == q) {
        break;
      }
      nowi = nowi + (magics[i].d == 'L' ? -1: 1);
            i++;
      if (nowi < 0 || nowi > n-1) {
        break;
      }
      now = s[nowi];
    }
    if (nowi > n-1) {
      ub = next;
    } else {
      lb = next;
    }
  }
  res -= (n-ub);
 }
  
  cout << res << endl;
}
