// top down approach
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

const ll sz=100001;
ll n,k,a[sz];
bool dp[sz];

int main()
{
    fastio;
    ll i,j;
    cin>>n>>k;
    for(i=0;i<n;i++)cin>>a[i];
    
    // dp[i] = true if first player can win if initial k==i
    dp[0] = 0;
    for(i=1;i<=k;i++){
        dp[i] = false;
        for(j=0;j<n;j++)
            if(a[j]<=i && !dp[i-a[j]])
                dp[i] = true;
    }
    if(dp[k]) cout<<"First";
    else cout<<"Second";
    

    
}