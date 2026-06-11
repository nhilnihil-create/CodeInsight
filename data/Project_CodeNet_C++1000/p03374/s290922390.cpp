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

#define int ll

signed main () {
  cin.tie(0);
  cout << setprecision(10);

  ll n, c; cin >> n >> c;
  vll x(n), v(n);
  REP(i, n) {
    cin >> x[i] >> v[i];
  }

  // clockwise go
  vll sr(n);
  sr[0] = v[0] - x[0];
  FOR(i, 1, n) {
    sr[i] = sr[i-1] + v[i] - (x[i] - x[i-1]);
  }
  
  vll sl(n);
  sl[0] = v[n-1] - (c - x[n-1]);
  FOR(i, 1, n) {
    sl[i] = sl[i-1] + v[n-i-1] - (x[n-i] - x[n-i-1]);
  }

  vll ma1r(n);
  ma1r[0] = max(0ll, sr[0]);
  FOR(i, 1, n) {
    ma1r[i] = max(ma1r[i-1], sr[i]);
  }

  vll ma1l(n);
  ma1l[0] = max(0ll, sl[0]);
  FOR(i, 1, n) {
    ma1l[i] = max(ma1l[i-1], sl[i]);
  }

  vll ma2r(n);
  ma2r[0] = max(0ll, sr[0] - x[0]);
  FOR(i, 1, n) {
    ma2r[i] = max(ma2r[i-1], sr[i] - x[i]);
  }

  vll ma2l(n);
  ma2l[0] = max(0ll, sl[0] - (c - x[n-1]));
  FOR(i, 1, n) {
    ma2l[i] = max(ma2l[i-1], sl[i] - (c - x[n-i-1]));
  }


  // printv(sr);
  // printv(sl);
  // printv(ma1r);
  // printv(ma1l);
  // printv(ma2r);
  // printv(ma2l);

  ll ans = max(ma1r[n-1], ma1l[n-1]);
  FOR(i, 0, n-1) {
    // cout << i << ":" << ans << endl;
    ans = max(ans, max(ma1r[i] + ma2l[n-2-i], ma2r[i] + ma1l[n-2-i]));
  }
  cout << ans << endl;
}
