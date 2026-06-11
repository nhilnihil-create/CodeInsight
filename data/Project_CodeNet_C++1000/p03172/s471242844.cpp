#include<bits/stdc++.h>
#define ll long long 
#define ld long double 
#define rep(i,a,b) for(ll i=a; i<b; ++i)
#define BOOST std::ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define all(v) v.begin(),v.end()
#define sl(a) a.size()
#define mod 1000000007 
#define lcm(a,b) (a*b)/__gcd(a,b)
#define MAX 10000003
using namespace std;
void solve()
{
    ll n,k;  cin>>n>>k;
    ll arr[n];
    rep(i,0,n)  cin>>arr[i];
    vector<vector<ll>> dp(n+1,vector<ll>(k+1,0));
    rep(i,0,n+1) dp[i][0]=1;
    rep(i,1,n+1)
    {
        vector<ll> prefix_sum(k+1,0);
        prefix_sum[0]=dp[i-1][0]%mod;
        rep(j,1,k+1) prefix_sum[j]+=(prefix_sum[j-1]+dp[i-1][j])%mod;
        rep(j,1,k+1)
        {
            if(j<=arr[i-1]) dp[i][j]=prefix_sum[j]%mod;
            else dp[i][j]=(prefix_sum[j]-prefix_sum[j-arr[i-1]-1]+mod)%mod;
           // rep(m,0,min(arr[i-1],j)+1) dp[i][j]+=dp[i-1][j-m];
        }
    }cout<<dp[n][k];
}
int main()
{
    #ifndef ONLINE_JUDGE
    // for getting input from input.txt
    freopen("input.txt","r",stdin);
    // for writing output to output.txt
    freopen("output.txt","w",stdout);
    #endif
    BOOST
    int T=1;  //cin>>T;
    while(T--) solve();
    return 0;
}
