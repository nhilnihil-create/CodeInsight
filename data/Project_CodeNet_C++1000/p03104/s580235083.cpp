///=======================///
/// coder: Andy - Tohrumi ///
///=======================///

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define rep(i, m, n) for(int i = m; i < n; i++)
#define Rep(i, m, n) for(int i = m; i > n; i--)
#define repl(i, m, n) for(ll i = m; i < n; i++)
#define Repl(i, m, n) for(ll i = m; i > n; i--)
#define fastio ios_base::sync_with_stdio(); cin.tie(0); cout.tie(0);
using namespace std;
typedef vector<int> vi;		typedef pair<int, int> ii;		typedef vector<ii> vii;

signed main() {
	fastio;
	ll a, b; cin >> a >> b;
	vector<ll> all;
	if(b - a < 10) {
		ll ans = a;
		repl(i, a + 1, b + 1) {
			ans ^= i;
		}
		cout << ans;
		return 0;
	}
	while(a % 4 != 0) {
		all.pb(a);
		a++;
	}
	while(b % 4 != 3) {
		all.pb(b);
		b--;
	}
	if(all.size() == 0) cout << 0 << endl;
	else {
		ll ans = all[0];
		rep(i, 1, all.size()) {
			ans ^= all[i];
		}
		cout << ans << endl;
	}
	return 0;
}
