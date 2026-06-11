#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
double pi = acos(-1.0);
const double EPS=1e-9;
#define MOD ll(1e9L+7)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)
#define t() ll tt;cin>>tt;while(tt--) 
#define t2() ll tt2; cin>>tt2; for(ll tti=1;tti<=tt2;tti++)
#define printcj "Case #"<<tti<<": "
#define debug1(x) cerr << #x << " = " << x << '\n';
#define debug2(x, y) cout << #x << " = " << x << "   " << #y << " = " << y << "\n";
#define debugarray(arr,n,x) { cout << "[" ; for(ll i=0;i<n;i++) cout<<arr[i]<<" "; cout<<"] , "<<#x<<" = "<<x<<'\n';}


int main()
{
    fastio;
    ll n;
    cin>>n;
    vector<ll>dp(1<<n);
    vector<vector<ll>>a(n,vector<ll>(n));
    for(ll i=0;i<n;i++)for(ll j=0;j<n;j++)cin>>a[i][j];

    // dp[i] = number of ways to select bitmask-i women

    dp[0] = 1;//base case, there is one way to select none women

    for(ll mask=0;mask<(1LL<<n)-1;mask++){
        ll men = __builtin_popcountll(mask);
        for(ll women=0;women<n;women++){
            if(a[men][women] && !(mask & (1LL<<women)) )
            {
                ll newmask = mask | (1LL<<women);
                dp[newmask] = (dp[newmask] + dp[mask])%MOD;
            }
        }
    }
    cout<<dp[(1LL<<n)-1];


    
}
