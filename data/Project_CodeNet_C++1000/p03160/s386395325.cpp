#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n+1);
    int dp[n+1]={INT_MAX};dp[1]=0;
    for(int i=1;i<=n;i++)
        cin>>v[i];
    for(int i=2;i<=n;i++){
        dp[i]=INT_MAX;
        for(int j=1;j<=2;j++){
           if(i>j){
               dp[i]=min(dp[i],abs(v[i]-v[i-j])+dp[i-j]);
           }
        }//cout<<dp[i]<<" ";
    }
    cout<<dp[n];
}