#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll dp[100005];
int main()
{
   ll n,k;
   cin>>n>>k;
   ll a[n];
   for(int i=0;i<n;i++){
    cin>>a[i];
    dp[i]=1000000000;
   }
   dp[n-1]=0;
   for(int i=n-2;i>=0;i--){
   for(int j=i+1;j<=min(i+k,n-1);j++){
    dp[i]=min(dp[i],dp[j]+abs(a[j]-a[i]));
   }
   }
   cout<<dp[0];
    return 0;
}
