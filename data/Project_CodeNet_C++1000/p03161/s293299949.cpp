#include <bits/stdc++.h>
# define lli long long int
# define pb push_back
# define ff first
#define ss second
using namespace std;
lli n,k;
lli dp[100005]={0},a[100005]={0};
lli find(lli n)
{
     for(lli i=1;i<n;i++)
     {
          dp[i]=10000000000ll;
          for(lli m=1;m<=k;m++)
          {
          if((i-m)>=0)
          {
          dp[i]=min(dp[i],abs(a[i]-a[i-m])+dp[i-m]);
          }
          }
     }
     return dp[n-1];
}
int main()
{
     lli n,j;
     cin>>n>>k;
     //memset(dp,10000000000,sizeof(dp));
     for(j=0;j<n;j++)
     {
          cin>>a[j];
     }
     //dp[0]=0;
     //dp[1]=abs(a[0]-a[1]);
     cout<<find(n);
}
