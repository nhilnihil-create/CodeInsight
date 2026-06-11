#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#define ll          long long
#define pb          push_back
#define INF         9223372036854777ll
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
#define N  405

ll dp[N][N];
ll n;
ll a[N];
ll pre(ll l,ll r)
{
    ll x=0;
    ll y=0;
    if(l!=0)
    {
        x=a[l-1];
    }
    y=a[r];
    return y-x;
}
ll dps(ll l,ll r)
{
    // cout<<l<<" "<<r<<endl;
    if(l>r)
        return INF;
    if(dp[l][r]!=-1)
        return dp[l][r];
    if(l==r)
        return 0;
    ll ans=INF;
    rep(i,l,r)
    {
        ans=min(ans,dps(l,i)+dps(i+1,r)+pre(l,r));
    }
    return dp[l][r]=ans;
}
void solve()
{
    cin>>n;
    rep(i,0,n)
    {
        cin>>a[i];
    }
    rep(i,1,n)
    {
        a[i]+=a[i-1];
    }
    memset(dp,-1,sizeof(dp));
    cout<<dps(0,n-1);
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