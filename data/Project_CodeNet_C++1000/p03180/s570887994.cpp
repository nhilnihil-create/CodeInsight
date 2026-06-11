#include<cstdio>
int n;
long long v[20][20];
long long cost[1<<17];
long long dp[1<<17];
long long best;

inline long long max(long long a, long long b){
	return a>b?a:b;
}

int main(){

 	scanf("%d", &n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%lld", &v[i][j]);
		}
	}
	for(int i=0;i<(1<<n);i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				if(i&(1<<j) && i&(1<<k))cost[i]+=v[j][k];
			}
		}
	}
	for(int i=1;i<(1<<n);i++){
		for(int j=i;j>0;j=(j-1)&i){
			dp[i] = max(dp[i], cost[j]/2+dp[i^j]);
			best = max(best, dp[i]);
		}
	}
	printf("%lld", best);
}
