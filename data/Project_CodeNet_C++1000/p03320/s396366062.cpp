#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

const int MOD = 1e9 + 7;
const int iINF = 1000000000;
const long long int llINF = 1000000000000000000;

using namespace std;
using ll = long long int;
using P = pair<int, int>;
using edge = struct {
  int to;
  int cost;
};
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define ALL(a) (a).begin(), (a).end()
#define MAX(vec) *std::max_element(vec.begin(), vec.end());
#define MIN(vec) *std::min_element(vec.begin(), vec.end());
#define MAXI(vec)                                                              \
  std::distance(vec.begin(), *std::max_element(vec.begin(), vec.end()));
#define MINI(vec)                                                              \
  std::distance(vec.begin(), *std::min_element(vec.begin(), vec.end()));
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

template <typename T, typename U> U read(ll V, T a, U b) {
  REP(i, V) {
    cin >> a;
    b.push_back(a);
  }
  return b;
}

ll s(ll n) {
  ll ans = 0;
  while (n > 0) {
    ans += n % 10;
    n /= 10;
  }
  return ans;
}

ll f(ll n) {
  double ans1 = llINF;
  ll ans2 = 0;
  REP(d, log10(n) + 2) {
    ll x = ((ll)pow(10, d + 1) * ((n / (ll)pow(10, d + 1)) + (ll)1)) - (ll)1;
    double y = (double)x / (double)s(x);
    if (ans1 > y) {
      ans2 = x;
      ans1 = y;
    }
  }
  return ans2;
}

int main() {
  ll K;
  ll now = 9;
  ll count = 0;
  cin >> K;
  for (ll i = 1; i < 10 && count < K; i++) {
    cout << i << endl;
    count++;
  }
  while (count < K) {
    now = f(now + 1);
    cout << now << endl;
    count++;
  }

  return 0;
}
