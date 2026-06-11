#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define F first
#define S second
#define bitcnt(v) __builtin_popcount(v)
#define all(v) v.begin(), v.end()


void solution(){
	int n; cin >> n;
	vector<long double> p(n); for(auto &x : p) cin >> x;
	// dp[i][j] -- prob of exactly j heads in i coins
	// dp[i][j] = dp[i-1][j]*(1-p) + dp[i-1][j-1]*p
	vector<vector<long double>> dp(n+1,vector<long double>(n+1,0));
	dp[0][0] = 1.0;
	// dp[i][0] -- 0 heads in i coins
	// dp[0][i] -- i heads in 0 throws
	// basically, j <= i always
	for(int i = 1; i <= n; i++){
		dp[i][0] = (1.0-p[i-1]) * dp[i-1][0];
	}
	long double ans = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			dp[i][j] = dp[i-1][j] * (1-p[i-1]);
			dp[i][j] += dp[i-1][j-1] * p[i-1];
			if(i == n && j > n/2) ans += dp[i][j];
		}
	}
	printf("%0.18Lf\n",ans);



}	


int main(){ 
	fio;
	int t;
	t = 1;
	// cin >> t;
	for(int i = 1; i <= t; i++){
		// cout << "Case #" << i << ": ";
		solution();
	} 
	return 0;
}