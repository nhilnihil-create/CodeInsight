#include<bits/stdc++.h>
#define mod (long)(1e9 + 7)
using namespace std;

long dp[100001][2];

long solve(int curr, int color, int par, vector<int> nbs[]) {
	// cout<<curr<<" "<<color<<"\n";
	if(dp[curr][color] != -1) return dp[curr][color];
	if(color == 1) {
		long res = 1;
		for(auto i : nbs[curr]) {
			if(i == par) continue;
			res = (res * solve(i, 0, curr, nbs)) % mod;
		}
		return dp[curr][color] = res;
	}
	long res = 1;
	for(auto i: nbs[curr]) {
		if(i == par) continue;
		// cout<<"->"<<i<<endl;
		long black = solve(i, 1, curr, nbs);
		long white = solve(i, 0, curr, nbs);
		long sum = (black + white) % mod;
		res = (res * sum) % mod;
	}
	// cout<<res<<endl;
	return dp[curr][color] = res;
	
}
	

int main() {
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	vector<int> nbs[n + 1];
	for(int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		nbs[u].push_back(v);
		nbs[v].push_back(u);
	}
	memset(dp, -1, sizeof dp);
	long res = solve(1, 0, 0, nbs);
	res = (res + solve(1, 1, 0, nbs)) % mod;
	cout<<res;
	return 0;
}