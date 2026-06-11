#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int dp[n+5][n+5];
    memset(dp,0,sizeof(dp));
    string s;
    cin>>s;
    dp[1][1]=1;
    int mo=1000000007;
    int prf[n+5]={0};
    int suf[n+5]={0};
    prf[1]=1;
    suf[1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(s[i-2]=='<')
                dp[i][j]=prf[j-1];
            else
                dp[i][j]=suf[j];
            //cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
        }

        prf[0]=0;
        for(int j=1;j<=i;j++)
            prf[j]=(prf[j-1] + dp[i][j])%mo;
        suf[i+1]=0;
        for(int j=i;j>=1;j--)
            suf[j]=(suf[j+1] + dp[i][j])%mo;
    }
    cout<<prf[n];
}
