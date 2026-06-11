#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define fi first
#define sec second
typedef long long int  ll;
typedef long double  ld;
#define pii pair<ll,ll> 
#define pic pair<ll,char>
#define vi vector< ll > 
#define vvi vector< vi > 
#define vpi vector< pii > 
#define vvpi vector< vpi > 
#define st  set <ll, greater <ll> >
#define mst  multiset <ll, greater <ll> >
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define mapp  unordered_map <ll, ll>
#define ppii pair< pii, pii > 
#define test(t) ll t;cin>>t;while(t--)
#define inarr(n) ll arr[n];for(ll i=0;i<n;i++)cin>>arr[i];
#define ingra(m) vvi arr(100005);for(ll i=0;i<m;i++){ll u,v;cin>>u>>v;arr[u].pb(v);arr[v].pb(u);}
#define mem(a,b) memset(a,b,sizeof(a))
#define inn freopen("input.txt", "r", stdin)
#define outt freopen("output.txt", "w", stdout)
#define all(arr) arr.begin(),arr.end()
ll power(ll x,ll y){ll res = 1;while(y){if(y&1) res = (res*x)%mod;y=y/2,x=(x*x)%mod;}return res%mod;}
pair < ll , ll > dp[1<<19];
signed main()
{
    fast;
    ll n;
    cin>>n;
    ll i;
    for(i=0;i<(1<<19);i++)
        dp[i].fi = -1e18,dp[i].sec = -1e18;
    for(i=0;i<(1<<n);i++)
    {
        cin>>dp[i].fi;
    }
    for(i=0;i<n;i++)
    {
        for(ll j=0;j<(1<<n);j++)
        {
            if((j&(1<<i)))
            {
                vi temp;
                temp.pb(dp[j].fi);
                temp.pb(dp[j].sec);
                temp.pb(dp[j^(1<<i)].fi);
                temp.pb(dp[j^(1<<i)].sec);
                sort(all(temp));
                reverse(all(temp));
                dp[j].fi = temp[0];
                dp[j].sec = temp[1];
            }
        }
    }
    ll ans = -1;
    for(i=1;i<(1<<n);i++)
    {
        ans = max(ans,dp[i].fi+dp[i].sec);
        cout<<ans<<"\n";
    }
}