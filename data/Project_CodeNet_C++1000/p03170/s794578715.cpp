#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[100005];

ll func(ll a[],ll n, ll k)
{
    if(k==0)
    {
     return 0;
    }
    if(k<0)
    return 1;

    if(dp[k]!=-1)
    return dp[k];
    for(ll i=0;i<n;i++)
    {
        if(func(a,n,k-a[i])==0)
         return dp[k]=1;
    }
   return dp[k]=0;
}
 
int main() {
   
   ll n,i,k;
   cin>>n>>k;
   ll a[n];
   for(i=0;i<n;i++)
    cin>>a[i];
    memset(dp,-1,sizeof(dp));
    if(func(a,n,k))
    cout<<"First"<<endl;
    else
      cout<<"Second"<<endl;

}