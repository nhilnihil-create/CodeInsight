#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tcase int _; cin >> _; while(_--)
const int MAX = 1e6;

int v[MAX][3];
int n;
int dp[MAX][3];
/*int memo[MAX][3];

int dp(int i, int op) {
	if(i < 0) return 0;
	int f = v[i][op] + dp(i-1, (op+1)%3);
	int s = v[i][op] + dp(i-1, (op+2)%3);
	return max(f,s);
}*/

void solve() {
	memset(v, 0, sizeof v);
	memset(dp, 0, sizeof dp);
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> v[i][0] >> v[i][1] >> v[i][2];
	}
	for(int i=1; i<=n; i++) {
		for(int j=0; j<3; j++) {
			dp[i][j] = v[i][j] + max(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]);	
		}
	}
	cout << max({dp[n][0], dp[n][1], dp[n][2]});
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

 	solve();

  	return 0;
}

