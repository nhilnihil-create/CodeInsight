#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define mod 1000000007
#define ff first
#define ss second
#define INF (int)1e9+1
#define INFLL (int)1e18+1
#define sz(bb) (int)bb.size()
#define all(qq) qq.begin(), qq.end() 
#define Max(a, b, c) max(a, max(b, c))
#define Min(a, b, c) min(a, min(b, c))
const double PI=acos(-1);
// #define int unsigned long long int//used when x<=2^64-1 && x>0
#define int long long//used when x<=2^63-1
//bool cmp if returns true it keeps 1st as first else swaps
typedef long long  ll;


void solve()
{
    int n;
    cin>>n;
    string str;
    cin>>str;
    int dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        dp[1][i]=1;
    }
    for(int i=1;i<=n;i++)
        dp[1][i]+=dp[1][i-1];
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(str[i-2]=='<')
            {
                dp[i][j]=dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=(dp[i-1][i-1]-dp[i-1][j-1]+mod)%mod;
            }
        }
        for(int j=2;j<=n;j++)
        {
            dp[i][j]+=dp[i][j-1];
            dp[i][j]%=mod;
        }
    }
    cout<<dp[n][n]<<"\n";
}
int32_t main()
{
    IOS;
    int t;
    // cin>>t;
    t=1;
    while(t--)
    {
        solve();
    }
    return 0;
}