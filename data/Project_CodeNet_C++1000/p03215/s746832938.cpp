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
typedef vector<ll> vl;

signed main() {
	fastio;
	vl beauty;
	int n, k; cin >> n >> k;
	ll sum = 0;
	int a[n]; rep(i, 0, n) cin >> a[i];
	rep(i, 0, n) {
		sum = 0;
		rep(j, i, n) {
			sum += a[j];
			beauty.pb(sum);
		}
	}
	bool check[beauty.size() + 1];
	int num;
	rep(i, 0, (int)beauty.size() + 1) check[i] = 1;
	Rep(j, 50, -1) {
		num = 0;
		Rep(i, (int)beauty.size() - 1, -1) {
			if(check[i]) if((beauty[i] >> j) & 1) num++;
		}
		if(num >= k) {
			Rep(i, (int)beauty.size() - 1, -1) {
				if(check[i]) if(!((beauty[i] >> j) & 1)) check[i] = 0;
			}
		}
	}
	ll ans = LLONG_MAX;
	rep(i, 0, (int)beauty.size()) {
		if(check[i]) ans &= beauty[i];
	}
	cout << ans;
 	return 0;
}

