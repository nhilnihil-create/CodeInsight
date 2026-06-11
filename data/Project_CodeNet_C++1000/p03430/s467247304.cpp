#include<bits/stdc++.h>
using namespace std;
const int N=305;
int dp[N][N][N];
int main()
{
    string s; int k;
    cin>>s>>k;
    int n=s.size();
    s='a'+s;
    for(int i=1;i<=n;i++)
    {
        dp[0][i][i]=1;
        if(i==n)
            continue;
        if(s[i]==s[i+1])
            dp[0][i][i+1]=2;
        else
            dp[0][i][i+1]=1;
    }
    for(int len=2;len<n;len++)
    {
        for(int i=1;i+len<=n;i++)
        {
            dp[0][i][i+len]=max(dp[0][i][i+len-1],dp[0][i+1][i+len]);
            if(s[i]==s[i+len])
                dp[0][i][i+len]=max(dp[0][i][i+len],dp[0][i+1][i+len-1]+2);
        }
    }
    for(int x=1;x<=n;x++)
    {
        for(int i=1;i<=n;i++)
        {
            dp[x][i][i]=1;
            if(i!=n) dp[x][i][i+1]=2;
        }
        for(int len=2;len<n;len++)
        {
            for(int i=1;i+len<=n;i++)
            {
                if(s[i]==s[i+len])
                    dp[x][i][i+len]=dp[x][i+1][i+len-1]+2;
                dp[x][i][i+len]=max(max(dp[x][i+1][i+len],dp[x][i][i+len-1]),max(dp[x][i][i+len],dp[x-1][i+1][i+len-1]+2));
            }
        }
    }
    cout<<dp[k][1][n]<<endl;
    return 0;
}
