
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define f(i,a,b) for (int i = a; i < b; i++)
#define Min(a,b) a=min(a,b)

const ll oo = 1e18;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	int p[n];
	int rt,lt; cin>>rt>>lt;
	f(i,0,n) cin>>p[i];
	ll dp[n][n];
	f(i,0,n) f(j,0,n) dp[i][j] = oo;
	f(i,0,n) {
		int gr = 0, ls = 0;	
		f(j,0,i) if (p[j]>p[i]) gr++;
		else ls++;
		dp[i][i] = 1LL*gr*rt+1LL*ls*lt;
		f(j,0,i) if (dp[i-1][j]!=oo) {
			if (p[j] > p[i]) // has to move left	
				Min(dp[i][j],dp[i-1][j]+lt);
			else { // has to move right ... moving left doesn't make sense
				Min(dp[i][j],dp[i-1][j]+rt);	
				// not moving
				Min(dp[i][i],dp[i-1][j]);
			}
		}
	}
	ll ans = oo;
	f(i,0,n) Min(ans,dp[n-1][i]);
	cout << ans << endl;

	return 0;
}

