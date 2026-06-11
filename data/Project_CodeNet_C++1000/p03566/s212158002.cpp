#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define REP(i, n) FOR(i, 0, n)
#define RFOR(i, a, b) for(int i=(a);i>=(b);i--)
#define RREP(i, n) FOR(i, n, 0)
#define MFOR(i, m) for(auto i=(m).begin();i!=(m).end();i++)
#define ALL(a) (a).begin(), (a).end()
#define SZ(x) ((int)(x).size())

typedef long long int ll;
typedef pair<int, int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;

const double eps = 1e-10;
const int MOD = 1000000007;
const double INF = 1000000;

struct Func {
  int l, r, v;

  Func(int a, int b, int c) {
    l = a;
    r = b;
    v = c;
  }

  double ve(double x) {
    if(l-eps < x && x < r+eps) {
      return v;
    } else if(x < l+eps) {
      return v + (l-x);
    } else {
      return v + (x-r);
    }
  }
};

void printv(vector<auto> const& s) {
  REP(i, s.size()) {
    cout << s[i] << endl;
  }
}

int main () {
  cin.tie(0);
  cout << setprecision(10);

  int n; cin >> n;
  vi t(n+1), v(n);
  t[0] = 0;
  REP(i, n) {
    cin >> t[i+1];
    t[i+1] += t[i];
  }
  REP(i, n) {
    cin >> v[i];
  }
  int ti = t[n];

  vector<Func> f(n+2, Func(0, 0, 0));
  REP(i, n) {
    f[i] = Func(t[i], t[i+1], v[i]);
  }
  f[n] = Func(0, 0, 0);
  f[n+1] = Func(ti, ti, 0);

  vector<double> ans(2*ti+1);
  double mi = INF;
  REP(i, 2*ti+1) {
    mi = INF;
    REP(j, n+2) {
      // cout << i << ":" << j << ":" << f[j].ve((double)(i)/2.0) << endl;
      if(mi > f[j].ve((double)(i)/2.0)-eps) {
        mi = f[j].ve((double)(i)/2.0);
      }
    }
    ans[i] = mi;
  }
  // REP(i, 2*ti+1) {
  //   cout << i / 2.0 << ":" << ans[i] << endl;
  // }
  double res = 0.0;
  REP(i, 2*ti) {
    res += 0.25 * (ans[i] + ans[i+1]);
  }
  cout << res << endl;
  
}
