#include<stdio.h>
#include <string.h>
#include<queue>
using std::queue;
typedef long long LL;
typedef std::pair<int, LL> Pil;
/*
dp[i][j]表示1~i的处理为有序，并且i在j 花费
dp[i+1]

*/



int pos[5005];

int roll = 0;
LL dp[2][5005];

LL min(LL x,LL y){
	return x < y ? x : y;
}
const LL INF = 4557430888798830399;
int main() {
	//freopen("in.txt", "r", stdin);
	memset(dp, 0x3f, sizeof dp);
	int n; scanf("%d", &n);
	LL A, B;scanf("%lld %lld", &A, &B);
	int x;
	for (int i = 1; i <=n; i++) {
		scanf("%d", &x);
		pos[x] = i;
	}
	dp[roll][0] = B;
	dp[roll][pos[1]] = 0;

	for(int i=2;i<=n;i++){
		memset(dp[roll ^ 1], 0x3f, sizeof dp[roll ^ 1]);
		for(int j=0;j<=n;j++)if(dp[roll][j]<INF){
				if(pos[i]>j){
					//留在原地
					dp[roll ^ 1][pos[i]] = min(dp[roll][j], dp[roll ^ 1][pos[i]]);
					//左移到[j~j+1)的合适位置
					dp[roll ^ 1][j] = min(dp[roll][j]+B, dp[roll ^ 1][j]);
				}
				else	
					//右移到[j~j+1)的合适位置
					dp[roll ^ 1][j] = min(dp[roll][j] + A, dp[roll ^ 1][j]);		
			}
		roll ^= 1;
	}
	LL ans = INF;
	for (int i=1;i<=n;i++){
		ans = min(ans, dp[roll][i]);
	}
	printf("%lld", ans);
}