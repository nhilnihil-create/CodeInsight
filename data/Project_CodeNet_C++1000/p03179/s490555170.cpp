#include <bits/stdc++.h>
#define pb push_back
#define int long long int
#define mod 1000000007
#define inf (1LL<<60)
#define f(i,a,b) for (int i= a; i <b; ++i)
using namespace std;
int dp[3005][3005];
void solve(string s,int n)
{
    dp[n][0]=(s[n-2]=='<')?0:1;
    dp[n][1]=(s[n-2]=='<')?1:0;
    for(int i=n-1;i>=2;i--)
    {
        int total=n-i+1;
        for(int j=0;j<=total;j++)
        {
            if(j==0)
            {
                if(s[i-2]=='>')
                {
                     for(int k=0;k<=total;k++)
                        dp[i][j]=(dp[i][j]+dp[i+1][k])%mod;
                }
            }
            else
            {
                if(s[i-2]=='<')
                    dp[i][j]=(dp[i][j-1]+dp[i+1][j-1])%mod;
                else
                    dp[i][j]=(mod+dp[i][j-1]-dp[i+1][j-1])%mod;
            }
        }
    }
}
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    string s;
    cin>>n;
    cin>>s;
    solve(s,n);
    int ans=0;
    for(int i=0;i<=n-1;i++)
        ans=(ans+dp[2][i])%mod;
    cout<<ans;
}

