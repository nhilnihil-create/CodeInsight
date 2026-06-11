#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
int main()
{
    ft
    int t,i,j,n,m,l,r;
    string s,p;
    cin>>s>>p;
    n=s.size();
    m=p.size();
    int dp[n+1][m+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0 || j==0)
            {
                dp[i][j]=0;
            }
            else if(s[i-1]==p[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    string ans;
    for(i=n,j=m;i>0 && j>0;)
    {
        if(s[i-1]==p[j-1])
        {
            ans+=s[i-1];
            i--,j--;
        }
        else
        {
            if(dp[i][j]==dp[i-1][j])
            {
                i--;
            }
            else
            {
                j--;
            }
        }
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<"\n";
    return 0;
}