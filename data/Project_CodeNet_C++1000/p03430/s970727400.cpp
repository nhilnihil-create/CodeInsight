#include<bits/stdc++.h>
#define int long long
using namespace std;
 

int dp[305][305][305];


signed main()
{
 
ios_base::sync_with_stdio(false);
cin.tie(NULL);  
cout.tie(0);   
 
 
#ifndef ONLINE_JUDGE
    if(fopen("INPUT.txt","r"))
    {
    freopen ("INPUT.txt" , "r" , stdin);
    freopen ("OUTPUT.txt" , "w" , stdout);
    }
#endif    

    string a;
    cin>>a;
    int k;
    cin>>k;
    int n=a.length();
    a="#"+a;
    for(int i=n;i>=1;i--)
    {
        dp[i][i][0]=1;
        for(int j=i+1;j<=n;j++)
        {
            for(int l=0;l<=k;l++)
            {
                if(a[i]==a[j])
                {
                    dp[i][j][l]=dp[i+1][j-1][l]+2;
                }
                else
                {
                    if(l>0)
                        dp[i][j][l]=dp[i+1][j-1][l-1]+2;
                } 
                dp[i][j][l]=max({dp[i][j][l],dp[i+1][j][l],dp[i][j-1][l]});
            }
        }
    }

    int mx=0;
    for(int i=0;i<=k;i++)
        mx=max(mx,dp[1][n][i]);
    cout<<mx;

}