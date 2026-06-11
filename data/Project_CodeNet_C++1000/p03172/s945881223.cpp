#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod = 1e9L+7;
int n;
vector<int> inp;
vector<vector<ll>> dp;

ll candp (int k,int i=0)
{
    //cout<<i<<" "<<j<<" "<<c<<" "<<sum<<'\n';
    if(k==0) return 1;
    if(i == n) return 0;
    if(dp[i][k] != -1) return dp[i][k];

    ll ans = 0;
    for(int a=0;a<=inp[i];a++)
    {
        if(k-a>=0)
        {
            ans += candp(k-a,i+1);
            ans%=mod;
        }
        else break;
    }
    return dp[i][k]=ans;
}

ll cf_solver(int k)
{
    vector<vector<ll>> cf_dp(k+1,vector<ll> (n+1,1));

    for(int a=1;a<=k;a++)
    {
        for(int i=1;i<=n;i++)
        {
            ll ans=0;
            int sub = min(a,inp[i]);
            sub++;
            if(a-sub == -1) ans = cf_dp[a][i-1] ;
            else ans = cf_dp[a][i-1] - cf_dp[a-sub][i-1];
            if(ans < 0) ans += mod;
            ans += cf_dp[a-1][i];
            ans %= mod;

            cf_dp[a][i] = ans;
        }
    }

    ll ret_val = cf_dp[k][n];
    if(k>0) ret_val -=  cf_dp[k-1][n];
    if(ret_val < 0) ret_val += mod;
    ret_val %= mod;
    return ret_val;
}

int main()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); cout.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int k;
    cin>>n>>k;
    inp.resize(n+1);
    dp.assign(n+1,vector<ll> (k+1,-1));

    for(int i=1;i<=n;i++)
    {
        cin>>inp[i];
    }

    //cout<<candp(k)<<'\n';
    cout<<cf_solver(k)<<'\n';

}
