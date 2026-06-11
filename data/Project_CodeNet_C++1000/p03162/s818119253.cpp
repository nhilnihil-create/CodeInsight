#include<bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pii pair<int,int>
#define ll long long int
#define ull unsigned long long int
#define inf LONG_MAX;
using namespace std;
ll n;
ll a[4][100005],dp[4][100005];
int main()
{
    fast_io
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[1][i]>>a[2][i]>>a[3][i];
    dp[1][1]=a[1][1];
    dp[2][1]=a[2][1];
    dp[3][1]=a[3][1];
    for(int i=2;i<=n;i++)
    {
        dp[1][i]=a[1][i]+max(dp[2][i-1],dp[3][i-1]);
        dp[2][i]=a[2][i]+max(dp[1][i-1],dp[3][i-1]);
        dp[3][i]=a[3][i]+max(dp[1][i-1],dp[2][i-1]);
    }
    cout<<max(dp[1][n],max(dp[2][n],dp[3][n]))<<endl;
}
