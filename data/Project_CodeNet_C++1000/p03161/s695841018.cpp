#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    int a[n];
    const long long INF=1LL<<60;
    long long dp[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)dp[i]=INF;
    dp[0]=0;
    for(int i=0;i<n;i++){
        for(int j=1;j<=k;j++){
            if(i+j>=n)continue;
            dp[i+j]=min(dp[i+j],dp[i]+abs(a[i]-a[i+j]));
        }
    }
    cout<<dp[n-1]<<endl;
    return 0;
}