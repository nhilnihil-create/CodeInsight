#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define BIT(X, i) ((X>>i)&1)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define r_all(a) (a).rbegin(), (a).rend()
#define in(x) cin>>x
#define ina(x, n) rep(x_i,n) cin>>x[x_i]
#define outa(x, n) rep(x_i,n) cout<<x[x_i]<<" \n"[x_i==n-1]

typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll, ll> pll;
typedef vector<pll> vll;
typedef priority_queue<ll> pq;

const int MOD = 1e9+7;
const int INF = (1<<30);
const ll INFL = (1L<<62);

int main() {
  int n, K; cin >> n >> K;
  vll xys;
  rep(i,n) {
    ll x, y; cin >> x >> y;
    xys.pb(mp(x, y));
  }
  ll ans = INFL;
  rep(i,n) {
    ll x1 = xys[i].ff;
    rep(j,n) {
      ll x2 = xys[j].ff;
      rep(k,n) {
        ll y1 = xys[k].ss;
        rep(l,n) {
          ll y2 = xys[l].ss;
          if (x1 >= x2 || y1 >= y2) continue;
          int cnt = 0;
          rep(m,n) {
            ll x = xys[m].ff, y = xys[m].ss;
            if (x1 <= x && x <= x2 && y1 <= y && y <= y2) {
              cnt++;
            }
          }
          ll area = (x2-x1) * (y2-y1);
          if (cnt >= K) {
            ans = min(ans, area);
          }
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
