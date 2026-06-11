#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<iomanip>
#include<math.h>
#include<bitset>
#include<cassert>
#include<random>
#include<time.h>
#include<functional>
using namespace std;
using ll=long long;
using ld=long double;
using P=pair<ll,ll>;
#define MOD 1000000007LL
#define INF 1000000000LL
#define EPS 1e-10
#define FOR(i,n,m) for(ll i=n;i<(ll)m;i++)
#define REP(i,n) FOR(i,0,n)
#define DUMP(a) REP(d,a.size()){cout<<a[d];if(d!=a.size()-1)cout<<" ";else cout<<endl;}
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v)  sort(ALL(v));v.erase(unique(ALL(v)),v.end());
#define pb push_back

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	ll n, k, q;
	cin >> n >> k >> q;
	vector<ll> a(n);
	REP(i, n)  cin >> a[i];
	vector<ll> b = a;
	UNIQUE(b);
	sort(ALL(b));
	vector<bool> used(n, true);
	ll ans = INF;
	REP(i, b.size()) {
		REP(j, n) if(a[j] < b[i]) used[j] = false;
		ll l = b[i] - 1, r = INF;
		while(r - l > 1) {
			ll m = (l + r) / 2;
			ll cnt1 = 0, cnt2 = 0;
			vector<P> v;
			REP(j, n) {
				if(!used[j]) {
					v.pb(P(cnt1, cnt2));
					cnt1 = cnt2 = 0;
				} else {
					cnt1++;
					if(a[j] <= m) cnt2++;
				}
			}
			v.pb(P(cnt1, cnt2));
			ll cnt = 0;
			REP(j, v.size()) {
				cnt += max(0ll,min(v[j].first - k + 1, v[j].second));
			}
			if(cnt >= q) r = m;
			else l = m;
		}
		if(r != INF) ans = min(ans, r - b[i]);
	}
	cout << ans << endl;
	return 0;
}

/* --------------------------------------- */
