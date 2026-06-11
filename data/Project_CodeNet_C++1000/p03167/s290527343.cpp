#include<iostream>
#include<bits/stdc++.h>
#define rep(i,n) for(i=0;i<n;i++)
#define pb push_back
#define lli long long int
#define all(v) (v.begin(),v.end())
#define fr first
#define sc second
#define mp make_pair
using namespace std;
int k=pow(10,9)+7;
int main()
{
    int n,m,i,j;
    cin>>n>>m;
    char a[n][m];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++) cin>>a[i][j];
    }
    int dp[n][m];
    dp[0][0]=1;
    for(i=1;i<m;i++)
    {
        if(a[0][i]=='.') dp[0][i]=dp[0][i-1];
        else dp[0][i]=0;
    }
    for(i=1;i<n;i++)
    {
        if(a[i][0]=='.') dp[i][0]=dp[i-1][0];
        else dp[i][0]=0;
    }
    for(i=1;i<n;i++)
    {
        for(j=1;j<m;j++)
        {
            if(a[i][j]=='.') dp[i][j]=(dp[i-1][j]+dp[i][j-1])%k;
            else dp[i][j]=0;
        }
    }
    cout<<dp[n-1][m-1]%k;
}
