
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define f(i,a,b) for (int i = a; i < b; i++)
#define fr(i,a,b) for (int i = b-1; i >= a; i--)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	clock_t start = clock();
#endif

	int n; ll x;
	cin>>n>>x;
	ll a[n];
	f(i,0,n) cin>>a[i];
	ll pre[n];
	f(i,0,n) pre[i] = (i?pre[i-1]:0)+a[i];
	ll ans = 1e18;
	f(k,1,n+1) {
		ll res = k*x;	
		int p = 1;
		for (int j = n-1; j >= 0; j -= k, p++) {
			int i = max(0,j-k+1);
			ll f = (pre[j]-(i?pre[i-1]:0));
			ll g = (p==1?5:2*p+1);
			if (res < 1e18 && (ll(1e18)-res)/f/g) {
				res += f*g;	
			} else goto end;
		}
		ans = min(ans,res);
end:{}
	}
	cout << ans+n*x << endl;

#ifdef LOCAL
	cout << setprecision(12) << (long double)(clock()-start) / CLOCKS_PER_SEC << endl;
#endif
	
	return 0;
}

