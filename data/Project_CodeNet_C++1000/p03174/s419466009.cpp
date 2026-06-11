#include <stdio.h>
#define ll long long
const int mod = 1e9 + 7;

int n;

int mx[21][21];

ll dp[ (1<<21) ];


int main(){

	scanf("%d",&n);
	for(int i=0;i<n;i++) 
	for(int j=0;j<n;j++)
		scanf("%d",&mx[i][j]);
	dp[0] = 1;

	for(int mask = 0;mask<(1<<n);mask++){
		int a = __builtin_popcount(mask);
		for(int i = 0;i<n;i++){

			if(mask>>i&1 || mx[a][i] == 0 ) continue;
			int next = ( mask | (1<<i) ); 
			dp[ next ] += dp[mask];
			if(dp[ next ] > mod) dp[next]-=mod;

		}
	}
	printf("%lld",dp[ (1<<n)-1 ]);
}