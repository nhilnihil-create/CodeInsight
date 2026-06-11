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
#define sortvdi(xs) sort(xs.begin(), xs.end(), std::greater<long>())
#define lbv(xs, x) lower_bound(xs.begin(), xs.end(), x) - xs.begin()
#define ubv(xs, x) upper_bound(xs.begin(), xs.end(), x) - xs.begin()
#define bs(xs, x) binary_search(xs.begin(), xs.end(), x)

#define rep(i,n) for(auto i=0; i<(n); i++)

const int mod = 1000000007;

struct mint {
    ll x;
    mint(ll x=0):x(x%mod){}

    mint& operator+=(const mint a) {
        if((x += a.x) >= mod) x -= mod;
        return *this;
    }

    mint& operator-=(const mint a) {
        if((x -= mod-a.x) >= mod) x -= mod;
        return *this;
    }

    mint& operator*=(const mint a) {
        x = (x * a.x) % mod;
        return *this;
    }

    mint operator+(const mint a) const {
        mint res(*this);
        return res += a;
    }

    mint operator-(const mint a) const {
        mint res(*this);
        return res -= a;
    }

    mint operator*(const mint a) const {
        mint res(*this);
        return res *= a;
    }
};

mint dp[100005][13];

int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<long> d(n+1);
  fillLong(d, n);

  d[n] = 0;
  sortv(d);

  int cnts[37];
  rep(i, 37) {
    cnts[i] = 0;
  }

  int isPlus = true;
  rep(i, n+1) {
    if (isPlus) {
      cnts[12 + d[i]]++;
    } else {
      cnts[12 - d[i]]++;
      cnts[36 - d[i]]++;
    }
    isPlus = !isPlus;
  }

  int res = 12;

  rep(i, 37) {
    if(cnts[i] >= 2) res = 0;
    if(cnts[i] == 0) continue;
    for(int j = i+1; j < 37; j++) {
      if(cnts[j] >= 1) {
        res = min(res, j-i);
        break;
      }
    }
  }

  cout << res << endl;
}
