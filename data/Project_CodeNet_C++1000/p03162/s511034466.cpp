#include<bits/stdc++.h>
using namespace std;
int dp[100000][3];
int main(){
	int n;
	scanf("%d",&n);
	for(int i = 0; i < n; i++)
		scanf("%d %d %d",&dp[i][0],&dp[i][1],&dp[i][2]);
	for(int i = 1; i < n; i++){
		dp[i][0] = max(dp[i-1][1],dp[i-1][2]) + dp[i][0];
		dp[i][1] = max(dp[i-1][0],dp[i-1][2]) + dp[i][1];
		dp[i][2] = max(dp[i-1][0],dp[i-1][1]) + dp[i][2];	
	}
	printf("%d\n", max(dp[n-1][0], max(dp[n-1][1],dp[n-1][2])));
	return 0;
}