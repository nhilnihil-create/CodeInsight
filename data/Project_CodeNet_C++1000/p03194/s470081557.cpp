#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

#define REP(i,n) for(ll (i) = (0); (i) < (n); ++i)
#define PB push_back
#define MP make_pair
#define FI first
#define SE second
#define ALL(v) v.begin(),v.end()
#define INF 1100000000
#define LLINF 1000000000000000000LL
#define MOD 1000000007
#define Decimal fixed << setpresicion(20)


typedef long long ll;
typedef pair<ll, ll> P;

void prime_factor(ll n, map<ll, ll>& res) {
  for (ll i = 2; i * i <= n; i++) {
    while (n % i == 0) {
      res[i]++;
      n /= i;
    }
  }
  if (n != 1) res[n] = 1;
}

ll mypow(ll a, ll n)
{
  ll ret = 1;
  for (int i = 0; i < n; i++) 
    ret *= a;
  return ret;
}

int main()
{
  ll N, P; cin >> N >> P;
  map<ll, ll> mp;
  prime_factor(P, mp);
  ll ans = 1;
  for (auto e : mp) {
    if (e.SE >= N) ans *= mypow(e.FI,(e.SE/N));
  }
  cout << ans << endl;
  return 0;
}

