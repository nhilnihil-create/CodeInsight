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

const int N=2097153;
int n;
int arr[22][22];
int dp[22][N];
int fun(int x, int mask)
{
    if(x<0)
        return (mask==(1<<n)-1);
    if(dp[x][mask]!=-1)
        return dp[x][mask];
    dp[x][mask]=0;
    for(int i=0;i<n;i++)
    {
        if(arr[x][i] && ((mask&(1<<i))==0))
        {
            dp[x][mask]+=0LL+fun(x-1, mask^(1<<i));
            dp[x][mask]%=mod;
        }
    }
    return dp[x][mask];
}
void solve()
{
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<(1<<n);j++)
            dp[i][j]=-1;
    cout<<fun(n-1, 0)<<"\n";
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