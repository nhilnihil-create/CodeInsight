#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    string s,p;
    cin>>s>>p;
    int n=s.length(),m=p.length();
    int dp[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0||j==0)
            {
                dp[i][j]=0;
            }
            else if(s[i-1]==p[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    string res;
    int i=n,j=m;
    while(i>0&&j>0)
    {
        if(s[i-1]==p[j-1])
        {
            res+=s[i-1];
            i--;
            j--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    reverse(res.begin(),res.end());
    cout<<res<<endl;
    return 0;
}
