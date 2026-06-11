#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;
const LL N = 1000000007;

LL dp[3005][3005] = {0};
LL pre[3005] = {0};
LL n;
char c[3005] = {0};

int main(){
	cin >> n;
	for(LL i = 2;i <= n;i ++) cin >> c[i];
	dp[1][1] = 1;
	for(LL i = 2;i <= n;i ++){
		for(LL j = 1;j <= i;j ++) pre[j] = (pre[j - 1] + dp[i - 1][j]) % N;
		for(LL j = 1;j <= i;j ++){
			if(c[i] == '>') dp[i][j] = pre[i - 1] - pre[j - 1];
			if(c[i] == '<') dp[i][j] = pre[j - 1];
			dp[i][j] = (dp[i][j] + N) % N;
		}
	}
	LL ans = 0;
	for(LL i = 1;i <= n;i ++) ans = (ans + dp[n][i]) % N;
	printf("%lld\n",ans);
	return 0;
}
//