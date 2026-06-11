#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>dp(n+1,100000);
    dp[0]=0;
    for(int i=0;i<n;i++){
        int nine=1,six=1;
        for(int j=(n-i)/9;j>0;j/=9)nine*=9;
        for(int j=(n-i)/6;j>0;j/=6)six*=6;
        dp[i+nine]=min(dp[i+nine],dp[i]+1);
        dp[i+six]=min(dp[i+six],dp[i]+1);
    }
    cout<<dp[n]<<endl;
    return 0;
}