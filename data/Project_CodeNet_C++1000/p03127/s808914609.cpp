#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define REP(i, n) for (int i = 0; i < (n); i++)

const long double EPS = 1e-10;
const long long INF = 1e18;
const long double PI = acos(-1.0L);

int main() {
  ll N;
  cin >> N;
  ll ans = 0;
  REP(i, N) {
    ll a;
    cin >> a;
    ans = __gcd(a, ans);
  }
  cout << ans << endl;

  return 0;
}