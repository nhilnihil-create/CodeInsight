#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
const int maxn=2e5+5;
int a[maxn];
int n;
int dp[maxn][2];
int sum[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		dp[i][0]=(dp[i-1][0]+dp[i-1][1])%MOD;
		if(a[i]!=a[i-1]){
			dp[i][1]=sum[a[i]];
			sum[a[i]]=(sum[a[i]]+dp[i][0])%MOD; 
		}
	}
	printf("%d\n",(dp[n][0]+dp[n][1])%MOD);
	return 0;
}