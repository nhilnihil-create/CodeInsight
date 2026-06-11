#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin>>n;
    long long a[n+1];
    for(int i=1;i<=n;i++)
        cin>>a[i];
    //cost size
    // pair<int, int> dp[n+1];
    // dp[0]={0, 0};
    // dp[1]={0, a[1]};
    // dp[2]={a[1]+a[2],a[1]+a[2]};
    // dp[3]={min(2*(a[1]+a[2])+a[3], 2*(a[2]+a[3])+a[1]) ,a[1]+a[2]+a[3]};
    // for(int i=4;i<=n;i++) {
    //     // combine ith with remaining i-1
    //     // size = dp[i-1].second+a[i]
    //     // cost = dp[i-1].first+(size)
    //     int opt1_size = dp[i-1].second+a[i];
    //     int opt1_cost = dp[i-1].first+opt1_size;
    //     // combine ith and i-1th and remaining
    //     int opt2_size = dp[i-2].second+a[i]+a[i-1];
    //     int opt2_cost = dp[i-2].first+a[i]+a[i-1]+opt2_size;
    //     bool flag=0;
    //     if(opt2_cost<opt1_cost)
    //         flag=1;
    //     if(flag)
    //         {dp[i].first=opt2_cost; dp[i].second=opt2_size;}
    //     else 
    //         {dp[i].first=opt1_cost; dp[i].second=opt1_size;}
    long long dp[n+1][n+1];
    long long prefix[n+1];
    prefix[0]=0;
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=n;j++)
            dp[i][j]=LLONG_MAX;
    }
    for(int i=0;i<=n;i++) {
        dp[i][i]=0;
    }
    for(int i=1;i<=n;i++)
        prefix[i]=prefix[i-1]+a[i];
    for(int l=1;l<=n-1;l++) {
        for(int i=1;i<=n-l;i++) {
            int j=i+l;
            for(int k=i;k<=j-1;k++) {
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+prefix[j]-prefix[i-1]);
            }
        }
    }
    // for(int i=0;i<=n;i++) {
    //     for(int j=i;j<=n;j++) {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    cout<<dp[1][n]<<endl;
    return 0;
}