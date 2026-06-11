#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;

LL n;
LL a[25][25] = {0};
LL sum[1 << 16] = {0};
LL dp[1 << 16] = {0};

int main(){
	scanf("%lld",&n);
	for(LL i = 1;i <= n;i ++){
		for(LL j = 1;j <= n;j ++){
			scanf("%lld",&a[i][j]);
		}
	}
	for(LL s = 0;s < (1 << n);s ++){
		for(LL i = 1;i <= n;i ++){
			for(LL j = 1;j <= n;j ++){
				if((s & (1 << (i - 1))) && (s & (1 << (j - 1)))) sum[s] += a[i][j];
			}
		}
		sum[s] >>= 1;
	}
	for(LL s = 0;s < (1 << n);s ++){
		for(LL t = s;t;t = (t - 1) & s){
			dp[s] = max(dp[s],dp[s ^ t] + sum[t]);
		}
	}
	printf("%lld\n",dp[(1 << n) - 1]);
	return 0;
}