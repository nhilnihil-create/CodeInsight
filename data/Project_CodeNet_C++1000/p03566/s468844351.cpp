#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define int ll
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<ll> VL;
typedef vector<VL> VVL;
typedef pair<int, int> PII;

#define FOR(i, a, n) for (ll i = (ll)a; i < (ll)n; ++i)
#define REP(i, n) FOR(i, 0, n)
#define ALL(x) x.begin(), x.end()
#define IN(a, b, x) (a<=x&&x<b)
#define MP make_pair
#define PB push_back
#ifdef int
const ll INF = (1LL<<60);
#else
const int INF = (1LL<<30);
#endif
const double PI = 3.14159265359;
const double EPS = 1e-12;
const int MOD = 1000000007;

template <typename T> T &chmin(T &a, const T &b) { return a = min(a, b); }
template <typename T> T &chmax(T &a, const T &b) { return a = max(a, b); }

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int t[210], v[210];
signed main(void)
{
  int n;
  cin >> n;
  REP(i, n) cin >> t[i];
  REP(i, n) cin >> v[i];

  double ret = 0, sp = 0;
  REP(i, n) {
    for(double j=0; j<t[i]; j+=0.5) {
      bool flag1 = true, flag2 = true;
      double ti = t[i]-j-0.5;
      FOR(k, i+1, n) {
        ti += t[k];
        if(sp+0.5-ti > v[k+1]) flag1 = false;
        if(sp-v[k+1] > ti) flag2 = false;
      }
      if(sp+0.5 <= v[i] && flag1 && (sp+0.5-(t[i]-j-0.5)) <= v[i+1]) {
        ret += sp*0.5;
        ret += 0.125;
        sp += 0.5;
      } else if(sp - v[i+1] <= t[i]-j-0.5 && flag2) {
        ret += sp*0.5;
      } else {
        sp -= 0.5;
        ret += sp*0.5;
        ret += 0.125;
      }
    }
  }
  cout <<fixed << setprecision(15) << ret << endl;

  return 0;
}