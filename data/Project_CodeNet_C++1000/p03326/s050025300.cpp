

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


using namespace std;

typedef long long ll;

static const long long MOD = 1000000007;

int N, M;
ll x[1005], y[10005], z[10005];
ll ans = -100000000000000000;

int main(void) {
    cin >> N >> M;
    rep(i, 0, N) scanf("%lld %lld %lld", &x[i], &y[i], &z[i]);

    for (int i=0; i<(1<<3); i++) {
        ll X = 1, Y = 1, Z = 1, sum = 0;
        vector<ll> v;
        if ((i>>0)&1) X = -1;
        if ((i>>1)&1) Y = -1;
        if ((i>>2)&1) Z = -1;
        rep(j, 0, N) v.pb(x[j]*X+y[j]*Y+z[j]*Z);
        sort(v.bg, v.en, greater<ll>());
        rep(j, 0, M) sum += v[j];
        ans = max(ans, sum);
    }

    printf("%lld\n", ans);

	return 0;
}
