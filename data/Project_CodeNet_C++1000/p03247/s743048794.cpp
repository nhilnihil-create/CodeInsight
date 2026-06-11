
#include <bits/stdc++.h>
#define pb push_back
#define REP(i, n) for (signed long long i = 0; i < (n); i++)
#define MOD 998244353
#define INF 98765431219876543
#define bitcnt(a) (ll) __builtin_popcount((a))
#define lb(a, b) lower_bound((a).begin(), (a).end(), (b))
#define ub(a, b) upper_bound((a).begin(), (a).end(), (b))
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<string, string> PS;

int main() {
  ll n;
  cin >> n;
  vector<ll> x, y;
  ll mod;

  REP(i, n) {
    ll a, b;
    cin >> a >> b;
    if (i == 0) {
      mod = abs((a + b) % 2);
    } else {
      if (mod != abs((a + b) % 2)) {
        return !printf("-1\n");
      }
    }
    if (mod == 0) {
      a++;
    }
    x.pb(a);
    y.pb(b);
  }

  if (mod == 0) {
    cout << 40 << endl;
    cout << 1 << " ";
  } else {
    cout << 39 << endl;
  }
  for (ll i = 38; i >= 0; i--) {
    printf("%lld", ((ll)1 << i));
    if (i)
      cout << " ";
  }
  cout << endl;
  char ansList[] = {'R', 'U', 'L', 'D'};
  REP(k, n) {
    if (mod == 0)
      cout << "L";
    ll X = 0, Y = 0;

    for (int i = 38; i >= 0; i--) {
      ll dis = INF, d = (ll(1) << i), xkari, ykari;
      ll lis[][4] = {{d, 0, -d, 0}, {0, d, 0, -d}};
      char ans;
      REP(j, 4) {
        if (dis > abs(X + lis[0][j] - x[k]) + abs(Y + lis[1][j] - y[k])) {
          dis = abs(X + lis[0][j] - x[k]) + abs(Y + lis[1][j] - y[k]);
          ans = ansList[j];
          xkari = X + lis[0][j];
          ykari = Y + lis[1][j];
        }
      }
      X = xkari;
      Y = ykari;
      cout << ans;
    }
    cout << endl;
    // cout << "Debug  " << X << " " << Y << " " << x[k] << " " << y[k] << endl;
  }
}