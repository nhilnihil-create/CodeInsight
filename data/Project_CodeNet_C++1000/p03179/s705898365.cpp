/*input
20
>>>><>>><>><>>><<>>
*/

//sometimes it's the people who no one imagines anything of 
//who do the things that no one can imagine.

//code author: iamxlr8

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define all(c) c.begin(),c.end()
#define mod 1000000007
#define inf 1000000000000000001
#define F first
#define S second
#define dbg(x) cout << #x << " = " << x << '\n'
#define off ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

ll add(ll a,ll b)
{
    return (a%mod+b%mod)%mod;
}

ll sub(ll a,ll b)
{
    return (a%mod-b%mod+mod)%mod;
}

void solve()
{
    ll n,l,r;
    string s;
    cin>>n;
    cin>>s;
    ll dp[n+1][n+1];
    memset(dp,0,sizeof(dp));
    dp[1][1]=1;
    for(ll len=2;len<=n;len++)
    {
        ll pre[len]={0};
        pre[0]=0;
        for(ll i=1;i<=len-1;i++)
            pre[i]=add(pre[i-1],dp[len-1][i]);
        for(ll last=1;last<=n;last++)
        {
            if(s[len-2]=='<')
            {
                l=1;
                r=last-1;
            }
            else
            {
                l=last;
                r=len-1;
            }
            if(l<=r)
                dp[len][last]=add(dp[len][last],sub(pre[r],pre[l-1]));
        }
    }
    ll ans=0;
    for(ll i=1;i<=n;i++)
        ans=add(ans,dp[n][i]);
    cout<<ans;
}

int main() 
{
    off;
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ll tests=1;
    // cin>>tests;
    while(tests--)
    {
        solve();
    }
    return 0;
}