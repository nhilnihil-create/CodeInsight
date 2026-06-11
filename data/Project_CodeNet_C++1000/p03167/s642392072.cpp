#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int H,W;
    cin>>H>>W;
    char arr[H][W];
    for(int i=0;i<H;i++)
    {
        for(int j=0;j<W;j++)
        {
            cin>>arr[i][j];
        }
    }
    long long int dp[H][W];
    memset(dp,0,sizeof(dp));
    for(int i=0;i<W;i++)
    {
        if(arr[0][i]=='.')
        {
            dp[0][i]=1;
        }
        else
        {
            break;
        }
    }
     for(int i=0;i<H;i++)
    {
        if(arr[i][0]=='.')
        {
            dp[i][0]=1;
        }
        else
        {
            break;
        }
    }
    for(int i=1;i<H;i++)
    {
        for(int j=1;j<W;j++)
        {
            if(arr[i][j]=='.')
            {
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%(long long int)(1e9+7);
                dp[i][j]%=(long long int)(1e9+7);
            }
            else
            {
                dp[i][j]=0;
            }
        }
    }
    cout<<dp[H-1][W-1];
    return 0;
}