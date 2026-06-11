#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main()
{
	int n;
	cin>>n;
	ll a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
    ll w[n];
    w[0]=a[0];
    for(int i=1;i<n;i++)
    w[i]=w[i-1]+a[i];
   
   
    ll dp[n][n];
    
    memset(dp,0,sizeof dp);

    for(int l=2;l<=n;l++)
    {
    for(int i=0;i<=n-l;i++)
    {
    int j=i+l-1;
    ll wt=w[j];
    if(i>=1)
    wt=wt-w[i-1];
    dp[i][j]=LLONG_MAX;
    for(int k=i;k<j;k++)
    {
    dp[i][j]=min(dp[i][k]+dp[k+1][j],dp[i][j]);
    }
    dp[i][j]+=wt;
    }
    }
    cout<<dp[0][n-1];
	return 0;
}