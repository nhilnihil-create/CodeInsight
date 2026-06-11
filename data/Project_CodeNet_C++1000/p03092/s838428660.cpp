#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INFL = 1e18;
const int INF = 1e9;
const int MN = 5050;
ll ord[MN];
ll w[MN];
ll dt[MN];
ll dp[MN][MN];
int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	ll a,b;
	cin >> a >> b;
	for(int i=0;i<n;i++) {
		cin >> w[i];
		w[i]--;
		ord[w[i]] = i+1;
	}
	memset(dp,0,sizeof(dp));
	for(int i=0;i<n;i++) {
		ll ma = INFL;
		for(int j=0;j<=n;j++) {
			if(i > 0) {
				ma = min(ma,dp[i-1][j]);
				if(j == ord[i-1]) {
					ma = min(ma,dt[i-1]);
				}
			} else {
				ma = 0;
			}
			if(j == ord[i]) {
				dt[i] = ma;
			}
			dp[i][j] = ma+(j>=ord[i]?a:b);
		}
	}
	ll res = INFL;
	for(int i=0;i<=n;i++) {
		res = min(res,dp[n-1][i]);
	}
	res = min(res,dt[n-1]);
	cout << res << '\n';
}
