#include<bits/stdc++.h>
using namespace std;
#define ll long long

inline ll int maxm (ll int a,ll int b)
{    if(a>b) return a;
     else return b;
}
inline ll int minm (ll int a,ll int b)
{    if(a>b) return b;
     else return a;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);cout.tie(NULL);

   int n,k;cin>>n>>k;int a[n];
   for(int i=0;i<n;i++)cin>>a[i];
   vector<int> dp(n,1000000001);
   dp[0]=0;
   for(int i=1;i<=k&&i<n;i++)dp[i]=abs(a[i]-a[0]);

   for(int i=k+1;i<n;i++)
   {  for(int j=1;j<=k&&(i-j)>=0;j++)
       {dp[i]=min(dp[i-j]+abs(a[i]-a[i-j]),dp[i]);}
   }
   cout<<dp[n-1];

 }
