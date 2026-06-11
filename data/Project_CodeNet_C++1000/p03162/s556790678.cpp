#include<bits/stdc++.h>

using namespace std;
const int N = 1e5+7;

int a[N],b[N],c[N];
int dp[N][3];


int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
	for(int i=1;i<=n;i++){
		dp[i][0] = max(dp[i-1][1]+b[i],dp[i-1][2]+c[i]);
		dp[i][1] = max(dp[i-1][0]+a[i],dp[i-1][2]+c[i]);
		dp[i][2] = max(dp[i-1][0]+a[i],dp[i-1][1]+b[i]);
	}
	cout<<max(dp[n][0],max(dp[n][1],dp[n][2]));
	return 0;
} 