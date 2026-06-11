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

   int n;cin>>n;int a[n];
   for(int i=0;i<n;i++)cin>>a[i];
   int dp[n];
   dp[0]=0;
   dp[1]=abs(a[0]-a[1]);
   for(int i=2;i<n;i++)
   {
       dp[i]=min(abs(dp[i-1]+abs(a[i]-a[i-1])),abs(dp[i-2]+abs(a[i]-a[i-2])));
   }cout<<dp[n-1];
 }
