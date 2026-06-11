#include <bits/stdc++.h>

using namespace std;

int a[100007] = {};
bool dp[100007] = {};

int main() {
	
	int i,j;
	int N,K;
	
	cin >> N >> K;
	for( i=1; i<=N; i++) {
		cin >> a[i];
	}
	
	for( i=0; i<=K; i++) {
		bool flag = 0;
		for( j=1; j<=N; j++) {
			if( i - a[j] >= 0 && !dp[ i-a[j] ])
				flag = 1;
		}
		dp[i] = flag;
	}
	
	if( dp[K])
		printf("First\n");
	else
		printf("Second\n");
	
	return 0;
} 