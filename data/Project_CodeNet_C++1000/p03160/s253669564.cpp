#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n];
    const long long INF=1LL<<60;
    long long dp[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)dp[i]=INF;
    dp[0]=0;
    for(int i=1;i<n;i++){
        dp[i]=min(dp[i],dp[i-1]+abs(a[i]-a[i-1]));
        if(i>1)dp[i]=min(dp[i],dp[i-2]+abs(a[i]-a[i-2]));
    }
    cout<<dp[n-1]<<endl;
    return 0;
}