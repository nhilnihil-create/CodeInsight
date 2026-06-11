#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
 ll n,k;
 ll dp[110][100010];// (i,x)n of ways to have distribute x candies for the first i kids
 ll dp2[110][100010];// prefix sum of dp  dp2[i][x] sum of dp [i][0,1,2,...x]
 ll a[109];
 
 const ll mod=1e9+7;
 
 ll sum(int i,int left,int right){
     if(left!=0){
     return dp2[i][right]-dp2[i][left-1];}
      return dp2[i][right];
 }
 
  
int main()
{
    cin>>n>>k;
   
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
   
 
//cout<<sum(1,0,1);return 0;
     for(ll i =1;i<=n;i++){
       for(ll j=0;j<=k;j++){
           //j=total of candies distributed
           // if i want to have 10 in total and ai = 5 then i need at least 5 so i nueed sum from 5 upto 10
           
           if(i==1){
              if(j<=a[i]){
               dp[i][j]=1ll;}
           }else if(j-a[i]<=0){
              dp[i][j] = dp2[i-1][j] % mod;
           }else{
                dp[i][j]=(dp2[i-1][j]-dp2[i-1][j-a[i]-1]+mod)%mod;
           }if(j==0){
               dp2[i][j]=1;
           }else{
               dp2[i][j]=(dp2[i][j-1]+dp[i][j])%mod;
           }
          // cout<<dp[i][j]<<" "<<i<<" "<<j<<endl;
           
       }
           
       }
        //cout<<ans;
   cout<<dp[n][k]%mod;
}