#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n, m, x, dp[100010];
bool vis[15];
const int ms[10]= {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i){
		scanf("%d", &x);
		vis[x] = 1;
	}
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for(int i = 1; i <= 9; ++i){
		if(!vis[i]) continue;
		for(int j = ms[i]; j <= n; ++j){
			dp[j] = max(dp[j], dp[j - ms[i]] + 1);
		}
	}
	int res = n;
	while(res){
		for(int i = 9; i >= 1; --i){
			if(vis[i] && res >= ms[i] && dp[res] == dp[res - ms[i]] + 1){
				printf("%d", i);
				res -= ms[i];
				break;
			}
		}
	}
	return 0;
}
//c___s AK IOI