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
#define concat(xs, ys) (xs).insert((xs).end(), (ys).begin(), (ys).end())

const int mod = 1000000007;

string dp[10020];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  long n, m;
  cin >> n >> m;

  vector<int> a(m);
  fillInt(a, m);

  map<int, int> mp;
  mp[1] = 2;
  mp[2] = 5;
  mp[3] = 5;
  mp[4] = 4;
  mp[5] = 5;
  mp[6] = 6;
  mp[7] = 3;
  mp[8] = 7;
  mp[9] = 6;

  for(int i = n-1; i >= 0; i--) {
    for(auto x: a) {
      ostringstream ss;
      ss << x;
      if ((i+mp[x] < n && dp[i+mp[x]].length() > 0) || i+mp[x] == n) {
        if (dp[i+mp[x]].length() >= dp[i].length()) {
          dp[i] = dp[i+mp[x]] + ss.str();
        } else if (dp[i+mp[x]].length() == dp[i].length() - 1) {
          dp[i] = max(dp[i], dp[i+mp[x]] + ss.str());
        }
      }
    }
  }

  cout << dp[0] << endl;
}