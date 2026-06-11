#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pii>
#define all(a) (a).begin(),(a).end()
#define X first
#define Y second
#define inf 1e18+5
using namespace std;
const int mod=1e9+7;
void solve()
{
    int n; cin>>n;
    string s; cin>>s;
    int dp[n]; dp[0]=1;
    for(int i=1;i<n;i++)
    {
        int dp1[n];
        for(int j=0;j<=i;j++)
        {
            if(s[i-1]=='<')
            {
                if(j)dp1[j]=dp[j-1];
                else dp1[j]=0;
            }
            else
            {
                if(j)dp1[j]=(dp[i-1]-dp[j-1]+mod)%mod;
                else dp1[j]=dp[i-1];
            }
        }
        dp[0]=dp1[0];
        for(int j=1;j<=i;j++){dp[j]=dp[j-1]+dp1[j]; dp[j]%=mod;}
    }
    cout<<dp[n-1];
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    while(t--)solve();
    return 0;
}
