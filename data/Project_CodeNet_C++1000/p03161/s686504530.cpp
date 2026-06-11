#include<bits/stdc++.h>
using namespace std;

int32_t main(){
     int n,k;
     cin>>n>>k;
     int a[n];
     for(int i=0;i<n;++i) cin>>a[i]; 
     int dp[n];
     for(int i=0;i<n;++i) dp[i]=INT_MAX; 
     dp[0]=0;
     dp[1]=abs(a[0]-a[1]);
     
     for(int i=2;i<n;++i){
         for(int j=1;j<=k&& (i-j)>=0; ++j){
             dp[i] = min( dp[i-j]+abs(a[i-j]- a[i]) , dp[i] );
         }
     }

     cout<<dp[n-1];

    return 0;
}