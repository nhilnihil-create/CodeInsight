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

const int N=100005;
void solve()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=1;i<n;i++)
        arr[i]+=arr[i-1];
    int dp[n][n];
    for(int len=1;len<=n;len++)
    {
        for(int i=0;i<n;i++)
        {
            int j=i+len-1;
            if(j>=n)
                break;
            int cur=arr[j];
            if(i!=0)
                cur-=arr[i-1];
            if(j==i)
            {
                dp[i][j]=0;
                continue;
            }
            if(j==i+1)
            {
                dp[i][j]=cur;
                continue;
            }
            dp[i][j]=INFLL;
            for(int temp=i;temp<j;temp++)
            {
                dp[i][j]=min(dp[i][j], dp[i][temp]+dp[temp+1][j]+cur);
            }
        }
    }
    cout<<dp[0][n-1]<<"\n";
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