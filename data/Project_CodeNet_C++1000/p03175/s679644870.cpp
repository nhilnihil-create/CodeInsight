#include <bits/stdc++.h>
using namespace std;
#define ll long long int

const int mod = 1e9 + 7;
const int MAX = 1e5 + 5;
vector<int> v[MAX];
ll dp[MAX][2];

ll dfs(int i, int par, int c) {
	if(dp[i][c] != -1) {
		return dp[i][c] % mod;
	}
	dp[i][c] = 1;
	for(auto u:v[i]) {
		if(u == par) continue;
        dfs(u, i, 0);
		if(c == 1) {
			dp[i][c] = (dp[i][c] * dp[u][0])% mod;
		}
		else {
            dfs(u, i, 1);
			dp[i][c] = (dp[i][c] * (dp[u][0] + dp[u][1])) % mod; 
		}
	}
	return dp[i][c] % mod;
}

int main() {
	int n; cin >> n;
	for(int i = 0; i < MAX; i++) {
		dp[i][0] = -1;
		dp[i][1] = -1;
	}	
	for(int i = 0; i < n - 1; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	cout << (dfs(1, -1, 0) + dfs(1, -1, 1)) % mod << endl;
    return 0;
}