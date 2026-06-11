#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,t;
    cin>>s>>t;
    int n=s.length(),m=t.length();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==t[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else

                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    string ans="";
    while(n>0 && m>0)
    {
        if(s[n-1]==t[m-1])
        {
            ans.push_back(s[n-1]);
            n--;
            m--;
        }
        else
        {
            if(dp[n-1][m]>dp[n][m-1])
                n--;
            else
                m--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
    return 0;

}
