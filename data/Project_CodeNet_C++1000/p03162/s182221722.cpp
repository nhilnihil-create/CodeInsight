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
	vector<int> a(n);
	vector<int> b(n);
	vector<int> c(n);
	for(int i = 0; i < n; i++){
		cin >> a[i] >> b[i] >> c[i];
	}
	vector<vector<int>> dp(3,vector<int>(n+1,0));

	dp[0][1] = a[0];
	dp[1][1] = b[0];
	dp[2][1] = c[0];

	for(int i = 2; i <= n; i++){
		dp[0][i] = a[i-1] + max(dp[1][i-1], dp[2][i-1]);
		dp[1][i] = b[i-1] + max(dp[0][i-1], dp[2][i-1]);
		dp[2][i] = c[i-1] + max(dp[0][i-1], dp[1][i-1]);
	}

	cout << max({dp[0][n], dp[1][n], dp[2][n]}) << endl;




	
}	

int main(){ 

	fio; // fast input output
	int t;
	t = 1;
	// cin >> t;
	for(int i = 1; i <= t; i++){
		// GOOGLE //
		// cout << "Case #" << i << ": ";

		solution();
	} 
	return 0;
}
