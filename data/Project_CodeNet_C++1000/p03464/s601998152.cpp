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

  int k;
  cin >> k;

  vector<long> a(k);
  fillLong(a, k);

  long minX = 2;
  long maxX = 2;
  bool isOk = true;
  rep(i, k) {
    long next = a[k-i-1];
    if (next > maxX || (minX/next == maxX/next && (minX%next) && (maxX%next))) {
      isOk = false;
      break;
    }
    minX = ((minX + next - 1) / next) * next;
    maxX = (maxX / next) * next + next - 1;
  }

  if(isOk) {
    cout << minX << " " << maxX << endl;
  } else {
    cout << -1 << endl;
  }
}
