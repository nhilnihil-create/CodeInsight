


#include <bits/stdc++.h>
using namespace std;


#define ll long long

int mod=1e9+7;


ll ways(int a[],int n,int k){

    vector<vector<ll>> dp(n+1,vector<ll>(k+1,0));

    for(int i=0;i<=n;i++){
        dp[i][0]=1;

    }
    


    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++){

            // for(int cand=0;cand<=a[i-1];cand++){
            //     if(cand<=j){
            //         dp[i][j]=dp[i-1][j-cand];
            //         dp[i][j]%=mod;
            //     }else{
            //         break;
            //     }
            // } // it will take o(n*k^2) time complexity so we need to optimize it so: 
            // optimization :
            //
            
            dp[i][j]=(mod+dp[i][j-1]+dp[i-1][j]-((j-a[i-1]-1>=0)?dp[i-1][j-a[i-1]-1]:0))%mod;
            


        }
    }

    return dp[n][k];
}



int main() {
   
   int n,k;
   cin>>n>>k;
   int a[n];

   for(int i=0;i<n;i++){
       cin>>a[i];
   }

   cout<<ways(a,n,k);




}
