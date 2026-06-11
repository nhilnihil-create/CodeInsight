#include<bits/stdc++.h>
using namespace std;
#define ll long long

char a[1001][1001];
int mod = 1e9+7;

int dp[10001][10001];
ll solve(int i, int j, int n, int m){
	
	if(i==(n-1) && j==(m-1))
		return 1;
	
	if(i>=n || j>=m)
		return 0;
		
	if(a[i][j] == '#')
		return 0;
	
	if(dp[i][j] != -1)
		return dp[i][j];
	
	ll ans=0;
	
	ans = (solve(i+1, j, n, m) % mod) + (solve(i, j+1, n, m) % mod);
	
	return dp[i][j] = ans%mod;
}

void solve(){
	int n, m;
	cin >> n >> m;
	
	memset(dp, -1, sizeof dp);
	
	for(int i=0; i<n; i++)
		for(int j=0; j<m; j++)
			cin >> a[i][j];
			
	cout << solve(0, 0, n, m);
}

int main(){
	solve();
}
