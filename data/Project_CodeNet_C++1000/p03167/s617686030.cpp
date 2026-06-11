#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
ll M=1e9+7;
int main()
{
    ft
    int t,i,j,n,m,l,r;
    cin>>n>>m;
    string s[n+1];
    ll dp[n+1][m+1];
    for(i=0;i<n;i++)
    {
        cin>>s[i];
    }
    l=1;
    for(i=0;i<n;i++)
    {
        if(s[i][0]=='#')
        {
            l=0;
        }
        dp[i][0]=l;
    }
    l=1;
    for(i=0;i<m;i++)
    {
        if(s[0][i]=='#')
        {
            l=0;
        }
        dp[0][i]=l;
    }
    for(i=1;i<n;i++)
    {
        for(j=1;j<m;j++)
        {
            if(s[i][j]=='#')
            {
                dp[i][j]=0;
            }
            else
            {
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%M;
            }
        }
    }
    cout<<dp[n-1][m-1]<<"\n";
    return 0;
}