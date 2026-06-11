#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define all(a) (a).begin(),(a).end()
#define X first
#define Y second
using namespace std;
const int mod=1e9+7;
void solve()
{
    int n,k; cin>>n>>k;
    int a[n],b[k+1]; b[0]=1;
    for(int i=0;i<n;i++)cin>>a[i];
    int dp[k+1];
    memset(dp,0,sizeof(dp));
    dp[0]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=1;j<=k;j++)b[j]=(dp[j]+b[j-1])%mod;
        for(int j=1;j<=k;j++)
        {
            if(j-a[i]-1<0)dp[j]=b[j];
            else dp[j]=(b[j]-b[j-a[i]-1]+mod)%mod;
        }
    }
    cout<<dp[k];
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; t=1;
    while(t--)solve();
    return 0;
}
