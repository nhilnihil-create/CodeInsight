#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iomanip>

using namespace std;

#define REP(i, n) for(ll i = 0;i < n;i++)
#define REPR(i, n) for(ll i = n;i >= 0;i--)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
#define FORR(i, m, n) for(ll i = m;i >= n;i--)
#define REPO(i, n) for(ll i = 1;i <= n;i++)
#define ll long long
#define INF (ll)1 << 60
#define MINF (-1 * INF)
#define ALL(n) n.begin(),n.end()
#define MOD 1000000007
#define P pair<ll, ll>

ll n, ans = 0;
int main() {
	cin >> n;
	vector<ll> a(n), b(n);
	REP(i, n)cin >> a[i];
	REP(i, n)cin >> b[i];
	REP(i, 30) {
		ll now = 0, nv = 1ll << i, mod = 1ll << (i + 1);
		vector<ll> bb = b;
		REP(j, n)bb[j] %= mod;
		sort(ALL(bb));
		bb.push_back(INF);
		REP(j, n) {
			auto a1 = lower_bound(ALL(bb), nv - (a[j] % mod));
			auto a2 = lower_bound(ALL(bb), nv * 2 - (a[j] % mod));
			auto a3 = lower_bound(ALL(bb), nv * 3 - (a[j] % mod));
			auto a4 = lower_bound(ALL(bb), nv * 4 - (a[j] % mod));
			now += (a2 - bb.begin()) - (a1 - bb.begin());
			now += (a4 - bb.begin()) - (a3 - bb.begin());
		}
		if (now % 2 == 1)ans += nv;
	}
	cout << ans << endl;
}