#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll dp[100005];
int main()
{
   ll n;
   cin>>n;
   ll a[n];
   for(int i=0;i<n;i++){
    cin>>a[i];
   }
   dp[n-1]=0;
   for(int i=n-2;i>=0;i--){
    if(i==n-2){
        dp[i]=abs(a[i+1]-a[i]);
    }
    else{
    dp[i]=min(dp[i+1]+abs(a[i+1]-a[i]),dp[i+2]+abs(a[i+2]-a[i]));
    }
   }
   cout<<dp[0];
    return 0;
}
