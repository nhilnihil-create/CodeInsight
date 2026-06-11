#include<bits/stdc++.h>
// #define int  long long 

using namespace std;
int32_t  main(){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    int dp[n]={0};
    dp[0]=0;
    dp[1]=abs(a[0]-a[1]);
    dp[2]= min( dp[1]+abs(a[1] - a[2]),abs(a[0]-a[2]));
    for(int i=3;i<n;++i){
        dp[i] = min(  dp[i-1] + abs(a[i-1]-a[i]),  dp[i-2]+abs(a[i-2]-a[i])  );     
    }
    cout<<dp[n-1];
   return 0;
}