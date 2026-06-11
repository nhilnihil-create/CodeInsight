#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define ll long long
#define M 1000000007
#define sz(a) (ll)a.size()
#define pll pair<ll,ll>
#define rep(i,a,b) for(ll i=(ll)a;i<(ll)b;i++)
#define sep(i,a,b) for(ll i=(ll)a;i>=(ll)b;i--)
#define mll map<ll,ll>
#define vl vector<ll>
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(),a.end()
#define F first
#define S second
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ll n,k,dp[100005],a[105];
ll f(ll k)
{
    if(dp[k]!=-1)
        return dp[k];
    ll ans=0;
    rep(i,0,n)
    {
        if(k-a[i]<0)
            break;
        if(f(k-a[i])==0)
        {
            ans=1;
            break;
        }
    }
    dp[k]=ans;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    rep(i,0,n)
    cin>>a[i];
    memset(dp,-1,sizeof(dp));
    if(f(k)==1)
        cout<<"First\n";
    else
        cout<<"Second\n";
}
