#include<bits/stdc++.h>
#define mod (long)(1e9 + 7)
using namespace std;

long dp[21][(1<<21)];

long solve(int curr, int mask, int a[][21], int n) {
	// cout<< curr <<" " << mask <<"\n";
	if(curr == n) return 1;
	if(dp[curr][mask] != -1) return dp[curr][mask];
	long res = 0;
	for(int i = 0; i < n; ++i) {
		// cout<<a[curr][i]<<"->"<<((mask>>i)&1)<<"\t";
		if(a[curr][i] && ((mask>>i)&1) == 0) {
			res = (res + solve(curr + 1, mask | (1<<i), a, n))%mod;
		} 
	}
	// cout<<"*";
	return dp[curr][mask] = res;
}

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	int a[n][21];
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cin >> a[i][j];
		}
	}
	memset(dp, -1, sizeof dp);
	cout<<solve(0, 0, a, n);
	return 0;
}