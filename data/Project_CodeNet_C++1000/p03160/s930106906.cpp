#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100007],dp[1000007];
int32_t main()
{
 cin>>n;
 for(int i=0;i<n;i++)
   cin>>a[i],dp[i]=0;
 dp[0]=0;
 dp[1]=abs(a[1]-a[0]);
 for(int i=2;i<n;i++)
   dp[i]=min(dp[i-1]+abs(a[i]-a[i-1]),dp[i-2]+abs(a[i]-a[i-2]));
 cout<<dp[n-1]<<endl;
 return 0;
}