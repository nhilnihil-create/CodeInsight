#include<bits/stdc++.h>
using namespace std;
int main()
{
int n;
cin>>n;
int a[n],dp[n],i;
for(i=0;i<n;i++)
{
cin>>a[i];
}
dp[0]=0;
dp[1]=abs(a[0]-a[1]);
for(i=2;i<n;i++)
{
dp[i]=min((dp[i-2]+abs(a[i-2]-a[i])),(dp[i-1]+abs(a[i-1]-a[i])));
}
cout<<dp[n-1]<<endl;
}
