#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[100007],dp[1000007];
int32_t main()
{
 cin>>n>>k;
 for(int i=0;i<n;i++)
   cin>>a[i],dp[i]=INT_MAX;
 dp[0]=0;
 dp[1]=abs(a[1]-a[0]);
 for(int i=2;i<n;i++){
  for(int j=i-1;j>=0&&i-j<=k;j--)
    dp[i]=min(dp[i],dp[j]+abs(a[i]-a[j]));
 }
 cout<<dp[n-1]<<endl;
 return 0;
}