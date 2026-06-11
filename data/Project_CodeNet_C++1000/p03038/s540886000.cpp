# include <bits/stdc++.h>
# define rep(i, n) for(ll i = 0; i < (n); ++i)
# define reps(i, n) for(ll i=1, i##_len=(n); i<=i##_len; ++i)
# define rrep(i, n) for(ll i=((int)(n)-1); i>=0; --i)
# define rreps(i, n) for(ll i=((int)(n)); i>0; --i)
# define ll long long
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define optimize_cin() cin.tie(0); ios::sync_with_stdio(false)
# define P pair<int, int>
using namespace std;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
ll lmax(ll a, ll b){if(a>= b) return a;return b;}
ll lmin(ll a, ll b){if(a>= b) return b;return a;}
static const ll INF = 1e18;

int main() {
  int n, m; cin >> n >> m;
  vector<pair<ll, ll>> a;
  rep(i, n){
    ll x; cin >> x;
    a.pb(make_pair(x, 1));
  }
  rep(j, m){
    ll x, y; cin >> x >> y;
    a.pb(make_pair(y, x));
  }

  sort(ALL(a));
  reverse(ALL(a));

  ll ans = 0, i = 0;

  while(n){
    ans += a[i].first * lmin(a[i].second, n);
    n -= lmin(a[i].second, n);
    i++;
  }

  cout << ans << endl;
}
