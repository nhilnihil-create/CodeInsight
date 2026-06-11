#include<bits/stdc++.h>
#define LLI long long int
#define MOD 1000000007
using namespace std;

vector<int> adj[100007];
LLI dp[100007][0] = {};

void DFS( int x, int p) {
	
	LLI w = 1;
	LLI b = 1;
	for( auto y:adj[x]) {
		if( y == p)
			continue;
		DFS( y, x);
		w *= ( dp[y][0] + dp[y][1] ) % MOD;
		w %= MOD;
		b *= dp[y][0];
		b %= MOD;
	}
	dp[x][0] = w;
	dp[x][1] = b;
}

int main() {
	
	int i,j;
	int N;
	
	cin >> N;
	for( i=1; i<=N-1; i++) {
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	DFS( 1, 1);
	printf("%lld\n", ( dp[1][0] + dp[1][1]) % MOD);
	
	return 0;
}