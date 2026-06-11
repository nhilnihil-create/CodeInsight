#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000+5;
const int mod = 1000000007;
char maze[maxn][maxn];
long long dp[maxn][maxn];
int main(int argc, char const *argv[])
{
	int n, m; scanf("%d %d\n", &n, &m);
	memset(dp, 0, sizeof dp);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%c", &maze[i][j]);
		}	
		scanf("\n");
	}
	bool set = true;
	for(int i = 0; i < n; i++){
		if(maze[i][0] == '#') set = false;
		if(set) dp[i][0] = 1;
		else dp[i][0] = 0;
	}
	set = true;
	for(int i = 0; i < m; i++){
		if(maze[0][i] == '#') set = false;
		if(set) dp[0][i] = 1;
		else dp[0][i] = 0;
	}
	for(int i = 1; i < n; i++){
		for(int j = 1; j < m; j++){
			if(maze[i][j] == '#') continue;
			dp[i][j] += dp[i][j-1] + dp[i-1][j];
			if(dp[i][j] > mod) dp[i][j] -= mod;
		}	
	}


	
	printf("%lld\n", dp[n-1][m-1] % mod);

	return 0;
}