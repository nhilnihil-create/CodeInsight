#include<bits/stdc++.h>
#define LLI long long int
#define ULTRA 2134567890
using namespace std;

int a[407];
LLI dp[407][407] = {};
LLI pre[407] = {};

LLI sum( int l, int r) {
	return pre[r] - pre[l-1];
}

int main() {
	
	int i,j;
	int N;
	
	cin >> N;
	for( i=1; i<=N; i++)
		cin >> a[i];
	for( i=1; i<=N; i++) {
		pre[i] = pre[i-1] + a[i];
	}
	for( i=2; i<=N; i++) {
		for( j=1; j+i-1 <= N; j++) {
			dp[j][j+i-1] = (LLI) ULTRA * ULTRA;
			for( int k=j; k < j+i-1; k++) {
				dp[j][j+i-1] = min( dp[j][j+i-1], dp[j][k] + dp[k+1][j+i-1] + sum( j, j+i-1));
			}
		}
	}
	printf("%lld\n", dp[1][N]);
	return 0;
}