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

using P = pair<ll, ll>;

static const long long MOD = 1000000007;
static const long long LINF = (ll)(1e18+99);
static const int INF = 1e9+99;

ll ans = LINF*5, n, K;
vector<P> v;

int main(void) {
    cin >> n >> K;
    rep(i, 0, n) {
        ll x, y;
        cin >> x >> y;
        v.pb(mp(x, y));
    }

    rep(i, 0, n) rep(j, 0, n) rep(k, 0, n) rep(l, 0, n) {
        if (i==j && i==k && i==l) continue;
        ll sx = v[i].first, tx = v[j].first, sy = v[k].second, ty = v[l].second;
        ll c = 0;
        rep(m, 0, n) if (v[m].first>=sx && v[m].first<=tx && v[m].second>=sy && v[m].second<=ty) c++;
        if (c>=K) ans = min(ans, abs(sx-tx)*abs(sy-ty));
    }
    

    cout << ans << endl;

	return 0;
}
