#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ll          long long
#define pb          push_back
#define INF         9223372036854775807
#define    endl        '\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)    for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define lower(u)    transform(u.begin(), u.end(), u.begin(), ::tolower);//convert string u to lowercase;
#define upper(u)    transform(u.begin(), u.end(), u.begin(), ::toupper);
using namespace std;

using namespace __gnu_pbds; 
  
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
#define N  100005
ll dp[(1<<16)],n;
vi adj[17];
ll arr[16][16];
vi v;
// ll dps(ll x)
// {

// }
void solve()
{
    cin>>n;
    for(int i=1;i<(1<<n);i++)
    {
        adj[__builtin_popcount(i)].pb(i);
    }
    rep(i,1,n+1)
    {
        for(auto u:adj[i])
            v.pb(u);
    }
    rep(i,0,n)
    rep(j,0,n)
    cin>>arr[i][j];
    for(auto u:v)
    {
        // cout<<u<<endl;
        vi v1;
        ll co=__builtin_popcount(u);
        if(co==1)
            continue;
        rep(j,0,n)
        {
            if(u&(1<<j))
            {
                v1.pb(j);
            }
        }
        rep(i,0,v1.size())
        {
            rep(j,i,v1.size())
            dp[u]+=arr[v1[i]][v1[j]];
        }
        dp[u]=max(dp[u],0ll);
        for(int s=u;s;s=(s-1)&u)
        {
            dp[u]=max(dp[u],dp[s]+dp[s^u]);
        }
    }
    cout<<dp[(1<<n)-1]<<endl;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int TESTS=1;
//    cin>>TESTS;
    while(TESTS--)
    {
        solve();
    }
    return 0;
}