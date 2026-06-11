#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define endl '\n'
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
int x;
string s;
int dp[200009][2];
int f(int i,int done) //....####
{
    if (i==x)
        return 0;
    if (dp[i][done]!=-1)
        return dp[i][done];
    int mn=1e9;
    if (!done)
    {
        if (s[i]=='#')
        {
            mn=min(mn,f(i+1,0)+1);
            mn=min(mn,f(i+1,1));
        }
        else
        {
            mn=min(mn,f(i+1,0));
            mn=min(mn,f(i+1,1)+1);
        }
    }
    else
    {
        if (s[i]=='#')
            mn=min(mn,f(i+1,1));
        else
            mn=min(mn,f(i+1,1)+1);
    }
    return dp[i][done]=mn;
}
int main()
{
    FASTINOUT;
    cin>>x>>s;
    memset(dp,-1,sizeof dp);
    cout<<f(0,0);
    return 0;
}
