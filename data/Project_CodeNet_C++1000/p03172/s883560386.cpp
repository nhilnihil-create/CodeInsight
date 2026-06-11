#include<bits/stdc++.h>
#define LLI long long int
#define MOD 1000000007
using namespace std;

int N,K;
int a[107] = {};
LLI dp[100007][107] = {};

void add( int x, int y, int d) {
	if( x == 0) {
		dp[x][y] += d;
		dp[x][y] %= MOD;
		return;
	}
	while( x <= K) {
		dp[x][y] += d;
		dp[x][y] %= MOD;
		x += x & (-x);
	}
}

LLI ps( int x, int y) {
	LLI ret = 0;
	while( x) {
		ret += dp[x][y];
		ret %= MOD;
		x -= x & (-x);
	}
	ret += dp[x][y];
//	printf("query :: %d\n", ret);
	return ret;
}

LLI query( int l, int r, int y) {
	if( l == 0)
		return ps( r, y);
	else
		return ( ( ps( r, y) - ps( l-1, y) ) % MOD + MOD ) % MOD;
//		return  ps( r, y) - ps( l-1, y);
}

int main() {
	
	int i,j;
	
	cin >> N >> K;
	for( i=1; i<=N; i++)
		cin >> a[i];
	
	add( 0, 0, 1);
	for( i=1; i<=N; i++) {
		for( j=0; j<=K; j++) {
			LLI d = query( max( 0, j-a[i]), j, i-1);
			add( j, i, d);
		}
	}
	
	LLI ans = query( K, K, N);
//	for( i=0; i<=N; i++) {
//		printf("%d >>> ", i);
//		for( j=0; j<=K; j++) {
//			printf("%d ", query( j, j, i));
//		}
//		printf("\n");
//	}
//	for( i=0; i<=N; i++) {
//		printf("%d >>> ", i);
//		for( j=0; j<=K; j++) {
//			printf("%d ", dp[i][j]);
//		}
//		printf("\n");
//	}
	printf("%lld\n", ans);
	
	return 0;
}