#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
const int mxN=300, M=1e9+7;
int n, a[21][21];
ll dp[1<<21];
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	cin >> n;
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			cin >> a[i][j];
	dp[0]=1;
	for(int i=1; i<1<<n; ++i)
		for(int j=0; j<n; ++j)
			if(i>>j&1&&a[__builtin_popcount(i)-1][j])
				dp[i]=(dp[i]+dp[i^1<<j])%M;
	cout << dp[(1<<n)-1];
}