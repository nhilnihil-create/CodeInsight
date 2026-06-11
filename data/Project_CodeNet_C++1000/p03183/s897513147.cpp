#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pl;
typedef pair<pl,ll> tl;
const ll MN = 1010;
const ll MW = 10100;
tl w[MN];
ll dp[MN][MW];
int main() {
	ll n;
	cin >> n;
	for(int i=0;i<n;i++) {
		ll a,b,c;
		cin >> a >> b >> c;
		w[i] = {{a+b,b},c};
	}
	sort(w,w+n,greater<tl>());
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<n;i++) {
		ll wt = w[i].first.first-w[i].first.second;
		ll st = w[i].first.second;
		ll val = w[i].second;
		dp[i+1][st] = max(dp[i][st],val);
		for(int j=0;j<MW;j++) {
			if(dp[i][j] < 0) {continue;}
			dp[i+1][j] = max(dp[i][j],dp[i+1][j]);
			if(j >= wt) {
				ll nx = min(j-wt,st);
				dp[i+1][nx] = max(dp[i+1][nx],dp[i][j]+val);
			}
		}
	}
	ll res = 0;
	for(int i=0;i<MW;i++) {
		res = max(res,dp[n][i]);
	}
	cout << res << '\n';
}
