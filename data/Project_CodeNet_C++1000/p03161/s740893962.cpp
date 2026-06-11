#include<bits/stdc++.h>

using namespace std;
const int N = 1e5+7;

int a[N];
int dp[N];

int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	for(int i=2;i<=n;i++){
		dp[i] = 1e9;
		for(int j=1;j<=k&&i-j>=1;j++){
			dp[i] = min(dp[i-j]+abs(a[i]-a[i-j]),dp[i]);
		}
	}
	cout<<dp[n]<<"\n";
	return 0;
}