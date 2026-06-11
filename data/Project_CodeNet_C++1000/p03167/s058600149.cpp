#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char> >ar(n,vector<char>(m));
    vector<vector<long long int> >dp(n,vector<long long int>(m));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>ar[i][j];
        }
    }
    bool flag=true;
    for(int i=0;i<n;i++)
    {
        dp[i][0]=1;
        if(ar[i][0]=='#')
            flag=false;
        if(flag==false)
            dp[i][0]=0;
    }
    flag=true;
    for(int i=0;i<m;i++)
    {
        dp[0][i]=1;
        if(ar[0][i]=='#')
            flag=false;
        if(flag==false)
            dp[0][i]=0;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(ar[i][j]=='#')
                dp[i][j]=0;
            else
            {
                dp[i][j]=(dp[i-1][j]%mod+dp[i][j-1]%mod)%mod;
            }
        }
    }
    cout<<dp[n-1][m-1];
    return 0;
}

