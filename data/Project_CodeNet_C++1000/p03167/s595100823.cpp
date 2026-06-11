#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

char a[1010][1010];
ll dp[1010][1010];
void fn(ll i,ll j,ll h,ll w)
{
    memset(dp,0,sizeof(dp));
    for(i=0; i<h; i++)
    {
        if(a[i][0] == '.')
        dp[i][0] = 1;
        else
        break;
    }
    
    for(i=0; i<w; i++)
    {
        if(a[0][i] == '.')
        dp[0][i] = 1;
        else
        break;
    }
    
    for(i=1; i<h; i++)
    {
        for(j=1; j<w; j++)
        {
            if(a[i][j] == '#')
            continue;
            
            if(dp[i-1][j] > 0)
            {
                dp[i][j] += dp[i-1][j];
                dp[i][j] %= mod;
            }
            
            if(dp[i][j-1] > 0)
            {
                dp[i][j] += dp[i][j-1];
                dp[i][j] %= mod;
            }
        }
    }
    
    cout<<dp[h-1][w-1]%mod;
    return;
}
int main()
{
    ll i,j,h,w;
    cin>>h>>w;
    for(i=0; i<h; i++)
    {
        for(j=0; j<w; j++)
        {
            cin>>a[i][j];
        }
    }
    fn(0,0,h,w);
    return 0;
}