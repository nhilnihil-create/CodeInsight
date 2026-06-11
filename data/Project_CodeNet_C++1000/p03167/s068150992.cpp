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

int mod = 1e9 + 7;

void solution(){

	int n, m; cin >> n >> m;
	int A[n+1][m+1];
	memset(A,0,sizeof(A));
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			char x; cin >> x;
			if(x == '#') A[i][j] = 1;
		}
	}
	ll dp[n+1][m+1];
	memset(dp,0,sizeof(dp));
	dp[1][1] = 1;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(i == 1 && j == 1) continue;
			if(!A[i-1][j])
				dp[i][j] += dp[i-1][j];
			if(!A[i][j-1])
				dp[i][j] += dp[i][j-1];
			dp[i][j] %= mod;
		}
	}
	cout << dp[n][m] << endl;





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