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
    int n, k;
    cin>>n>>k;
    int arr[n];
    int mn=INF;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        mn=min(mn, arr[i]);
    }
    int dp[k+1];
    for(int i=1;i<mn;i++)
        dp[i]=1;
    dp[0]=1;
    for(int i=mn;i<=k;i++)
    {
        dp[i]=-1;
        for(int j=0;j<n;j++)
        {
            if(arr[j]>i)
                continue;
            int cur=1^(dp[i-arr[j]]);
            if(cur==0)
                dp[i]=0;
        }
        if(dp[i]==-1)
            dp[i]=1;
    }
    if(dp[k]==0)
        cout<<"First\n";
    else
        cout<<"Second\n";
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