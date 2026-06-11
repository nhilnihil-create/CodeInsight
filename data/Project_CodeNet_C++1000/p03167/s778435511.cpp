#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
char a[1001][1001];
int dp[1001][1001];
int solve(int h,int w)
{
    int c=0;
    int d=0;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        {
            if(i==0)
            {
                if(a[i][j]=='.' && c==0)
                dp[i][j]=1;
                else
                c++;
            }
            else if(j==0)
            {
                if(a[i][j]=='.' && d==0)
                dp[i][j]=1;
                else
                d++;
            }
            else
            {
                if(a[i][j]=='.')
                {
                    if(a[i-1][j]=='.' && a[i][j-1]=='.')
                    {
                        dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
                    }
                    else
                    {
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                    }
                }
            }
        }
    }
    return dp[h-1][w-1]%mod;
}
int main()
{
    int h,w;
    cin >> h >> w;
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        cin >> a[i][j] ;
    }
    cout << solve(h,w) << endl;
}