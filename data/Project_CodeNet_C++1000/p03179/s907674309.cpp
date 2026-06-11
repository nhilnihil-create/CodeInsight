#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define fr(a,b) for(ll i = a; i < b; i++)
#define mod 1000000007
#define prllDouble(x) cout << fixed << setprecision(10) << x
#define triplet pair<ll,pair<ll,ll>>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

int dp[3001][3001][3];

int solve(string& oprs)
{
    int n = oprs.length();
    memset(dp, 0, sizeof dp);
    for(int idx = n; idx > 0; idx--)
    {
        int availNums = n - idx + 1;
        for(int smol = 0; smol <= availNums; smol++)
        {
            if(oprs[idx - 1] == '>')
            {
                dp[idx][smol][0] = (availNums > 1) ? dp[idx + 1][smol - 1][1] : smol;
            }
            else
            {
                dp[idx][smol][0] = (availNums > 1) ? dp[idx + 1][smol][2] : !smol;
            }
        }

        dp[idx][0][1] = dp[idx][0][0];
        dp[idx][availNums][2] = dp[idx][availNums][0];

        for(int i = 1; i <= availNums; i++)
            dp[idx][i][1] = (dp[idx][i][0] + dp[idx][i - 1][1]) % mod;

        for(int i = availNums - 1; i >= 0; i--)
            dp[idx][i][2] = (dp[idx][i][0] + dp[idx][i + 1][2]) % mod;

    }

    ll ans  = 0;
    for(int num = 1; num <= n + 1; num++)
    {
        ans = (ans + dp[1][num - 1][0]) % mod;
    }
    return ans;
}

int main(){
    ll i,j,t,n,m,x,p,k;
    fast_io;
    //cin>>t;
    t=1;
    while(t--)
    {
        cin>>n;
        string s;
        cin >> s;
        cout << solve(s);
    }
    return 0;
}
