#include<bits/stdc++.h>
#define MOD 1000000007
#define LLI long long int
using namespace std;

int N;
LLI dp[22][1<<21] = {};
int a[21][21] = {};

int main() {
	
	int i,j;
	int N;
	
	cin >> N;
	for( i=0; i<N; i++) {
		for( j=0; j<N; j++) {
			cin >> a[i][j];
		}
	}
	
	dp[0][0] = 1;
	for( i=0; i<N; i++) {
		for( j=0; j < N; j++) {
			if( !a[i][j])
				continue;
			for( int k=0; k<(1<<N); k++) {
				if( k&(1<<j) ) {
					dp[i+1][k] += dp[i][k^(1<<j)];
					dp[i+1][k] %= MOD;
				}
			}
		}
	}
	
	LLI ans = dp[N][(1<<N)-1];
	printf("%lld\n", ans);
	
	return 0;
}