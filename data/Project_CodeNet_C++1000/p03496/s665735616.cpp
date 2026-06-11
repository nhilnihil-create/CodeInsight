#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <string>

#define rep(i, a, b) for ( int i = (a); i < (b); i++ )
#define per(i, a, b) for ( int i = (b)-1; i >= (a); i--)
#define pb push_back
#define mp make_pair
#define bg begin()
#define en end()
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()

using namespace std;

typedef long long ll;
typedef long double ld;

using P = pair<int, int>;

static const long long MOD = 1000000007;
static const long long LINF = (ll)(1e18+99);
static const int INF = 1e9+99;

int n;
vector<ll> a;
vector<P> v;

ll mx = -10000000, mn = LINF;
ll mxi = 0, mni = 0;

int main(void) {
  cin >> n;
  rep(i, 0, n) {
    ll t;
    cin >> t;
    if (t>mx) {
        mx = t;
        mxi = i;
    }
    if (t<mn) {
        mn = t;
        mni = i;
    }
    a.pb(t);
  }


  if (abs(mx)>abs(mn)) {
      rep(i, 0, n) {
          if (i==mxi) continue;
          if (a[i]<0) {
              a[i] += a[mxi];
              v.pb(mp(mxi, i));
          }
      }
      rep(i, 0, n-1) {
          a[i+1] += a[i];
          v.pb(mp(i, i+1));
      }
  } else {
      rep(i, 0, n) {
          if (i==mni) continue;
          if (a[i]>0) {
              a[i] += a[mni];
              v.pb(mp(mni, i));
          }
      }
      for (int i=n-1; i>=1; i--) {
          a[i-1] += a[i];
          v.pb(mp(i, i-1));
      }

  }
  cout << sz(v) << "\n";
  for (auto x : v) printf("%d %d\n", x.first+1, x.second+1);
  
    return 0;
}

