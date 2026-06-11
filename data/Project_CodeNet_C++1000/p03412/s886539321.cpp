#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define REP(i, n) FOR(i, 0, n)
#define RFOR(i, a, b) for(int i=(a);i>=(b);i--)
#define RREP(i, n) RFOR(i, n, 0)
#define MFOR(i, m) for(auto i=(m).begin();i!=(m).end();i++)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((int)(x).size())

typedef long long int ll;
typedef pair<int, int> P;
typedef pair<ll, ll> Pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1 << 30;

template<typename T>
void printv(vector<T> const& s) {
  REP(i, SZ(s)) {
    cout << s[i] << " ";
  }
  cout << endl;
}

int main () {
  cin.tie(0);
  cout << setprecision(10);

  int n;cin >> n;
  vll a(n), b(n);
  REP(i, n) cin >> a[i];
  REP(i, n) cin >> b[i];

  ll ans = 0;
  REP(i, 30) {
    ll tmp = 0;
    vll c(n);
    REP(j, n) {
      c[j] = b[j] % (1ll<<(i+1));
    }
    sort(ALL(c));

    REP(j, n) {
      ll atmp = a[j] % (1 << (i+1));
      tmp += (lower_bound(ALL(c), 2*(1ll<<i) - atmp) - lower_bound(ALL(c), (1ll<<i) - atmp)) +
             (lower_bound(ALL(c), 4*(1ll<<i) - atmp) - lower_bound(ALL(c), 3*(1ll<<i) - atmp));
      tmp %= 2;
    }
    if(tmp) ans += 1ll<<i;
  }

  cout << ans << endl;
}
