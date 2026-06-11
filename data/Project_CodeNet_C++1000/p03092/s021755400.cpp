#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

ll dp[5001][5001];

int a[5001];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,A,B;
	cin>>n>>A>>B;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			dp[i][j]=1e18;
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=n;j++)
			if(a[i]>j){
				dp[i][j]=min(dp[i][j],dp[i-1][j]+A);
				dp[i][a[i]]=min(dp[i][a[i]],dp[i-1][j]);
			}
			else
				dp[i][j]=min(dp[i][j],dp[i-1][j]+B);
	cout<<*min_element(dp[n]+1,dp[n]+n+1)<<endl;
}
