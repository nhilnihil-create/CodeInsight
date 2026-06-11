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
#define N  21
ll dp[N][1<<21];
ll n;
ll arr[N][N];
ll dps(ll ind,ll rem)
{
    // cout<<ind<<" "<<rem<<endl;
    if(rem==0)
        return 1;
    if(ind==0)
    {
        rep(i,0,n)
        {
            if(((1<<i)==rem)&&arr[0][i]==1)
                return 1;
        }
        return 0;
    }
    if(dp[ind][rem]!=-1)
        return dp[ind][rem];
    dp[ind][rem]=0;
    rep(i,0,n)
    {
        if((rem&(1ll<<i))&&arr[ind][i]==1)
        {
            dp[ind][rem]=(dp[ind][rem]+dps(ind-1,rem-(1<<i)))%hell;
        }
    }
    return dp[ind][rem];
}
void solve()
{
    cin>>n;
    rep(i,0,n)rep(j,0,n)cin>>arr[i][j];
    memset(dp,-1,sizeof(dp));
    cout<<dps(n-1,(1<<n)-1);
    // rep(i,0,n)
    // {
    //     rep(j,0,8)
    //     {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    
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