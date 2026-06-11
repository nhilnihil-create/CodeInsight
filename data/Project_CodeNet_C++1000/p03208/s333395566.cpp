#include<bits/stdc++.h>
using namespace std; 
#define int long long
int32_t main()
{
  int n, k, i, j, l,min1=1e16; 
 cin>>n>>k; 
int a[n+1];
for(i=1;i<=n; i++) cin>>a[i];
sort(a+1,a+n+1);
int dp[n+1];dp[0]=0;
for(i=1;i<=n; i++)
 dp[i]=dp[i-1]+a[i];
 for(i=k;i<=n;i++)
    {
      j=a[i]-a[i-k+1];
   min1=min(min1,j);
 }
cout<<min1;
}
