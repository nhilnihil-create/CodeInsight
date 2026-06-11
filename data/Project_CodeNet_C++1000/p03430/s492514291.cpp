
#include <bits/stdc++.h>
using namespace std;

#define f(i,a,b) for (int i = a; i < b; i++)
#define fr(i,a,b) for (int i = b-1; i >= a; i--)
#define Max(a,b) a=max(a,b)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	clock_t start = clock();
#endif

	string s; cin >> s;
	int n = s.length();
	int K; cin >> K;
	int dp[n+1][n+1][K+1];
	f(i,0,n+1) f(j,0,n+1) f(k,0,K+1)
		dp[i][j][k] = 0;
	int ans = 0;
	f(i,0,n) fr(j,i,n) f(k,0,K+1) {
		if (s[i] == s[j]) {
			if (j) Max(dp[i+1][j-1][k],dp[i][j][k]+1+(i!=j));	
			else Max(ans,dp[i][j][k]+1+(i!=j));
		} else if (k) {
			if (j) Max(dp[i+1][j-1][k-1],dp[i][j][k]+1+(i!=j));
			else Max(ans,dp[i][j][k]+1+(i!=j));
		}
		if (i<n) Max(dp[i+1][j][k], dp[i][j][k]);
		if (j) Max(dp[i][j-1][k], dp[i][j][k]);
	}
	f(i,0,n+1) f(j,0,n+1) f(k,0,K+1)
		Max(ans,dp[i][j][k]);
	cout << ans << endl;

#ifdef LOCAL
	cout << setprecision(12) << (long double)(clock()-start) / CLOCKS_PER_SEC << endl;
#endif
	
	return 0;
}

