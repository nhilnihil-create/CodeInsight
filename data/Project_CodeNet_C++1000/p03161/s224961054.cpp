#include<bits/stdc++.h>
using namespace std;
int main()
{
long long int n,k;
cin>>n>>k;
long long int a[n],dp[n],i,j;
for(i=0;i<n;i++)
{
cin>>a[i];
dp[i]=999999999999;
}
dp[0]=0;
dp[1]=abs(a[0]-a[1]);
//cout<<dp[n-1]<<endl;
for(i=2;i<n;i++)
{
for(j=1;j<=min(i,k);j++)
{
dp[i]=min(dp[i],(dp[i-j]+abs(a[i-j]-a[i])));
}
}
cout<<dp[n-1]<<endl;
}
