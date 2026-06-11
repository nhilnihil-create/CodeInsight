#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INFL = 1e18;
const int MN = 5050;
ll dp[MN][MN];
ll dt[MN];
ll ord[MN];
int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	ll n,a,b;
	cin >> n >> a >> b;
	for(int i=0;i<n;i++) {
		int t;
		cin >> t;
		t--;
		ord[t] = i+1;
	}
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++) {
		ll ma = INFL;
		for(int j=0;j<=n;j++) {
			if(i > 0) {
				if(j == ord[i-1]) {
					ma = min(ma,dt[i-1]);
				}
				ma = min(ma,dp[i-1][j]);
			} else {
				ma = 0;
			}
			if(j == ord[i]) {
				dt[i] = ma;
			}
			dp[i][j] = ma + (j>=ord[i]?a:b);
		}
	}
	ll res = INFL;
	for(int i=0;i<=n;i++) {
		res = min(res,dp[n-1][i]);
	}
	res = min(res,dt[n-1]);
	cout << res << '\n';
}
