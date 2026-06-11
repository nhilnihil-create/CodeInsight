#include<bits/stdc++.h>
using namespace std;
int main(){
    long n,m;
    cin >> n >> m;
    long x[n];
    long y[n];
    long z[n];

    long ans = 0;

    for(int i=0;i<n;i++)cin >> x[i] >> y[i] >> z[i];
    for(int k=0;k<8;k++){
        long xsig = 1;
        long ysig = 1;
        long zsig = 1;
        if(k&1)xsig=-1;
        if(k&2)ysig = -1;
        if(k&4)zsig = -1;

        vector<vector<long> >dp(n+1,vector<long>(m+1,-999999999999999));
        for(int i=0;i<=n;i++)dp[i][0] = 0;

        for(long i=0;i<n;i++){
            long tmp = x[i]*xsig + y[i]*ysig + z[i]*zsig;
            for(int j=0;j<min(m,i+1);j++){
                dp[i+1][j+1] = max(dp[i][j+1],dp[i][j]+tmp);
            }
        }
        ans = max(ans,dp[n][m]);
    }
    cout << ans << endl;
}