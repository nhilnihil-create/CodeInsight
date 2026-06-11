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
ll dp[sz];
//return true if child win
bool ischildwin(ll currentk)
{
    if(currentk<0){
        return true;
    }
    else if(currentk==0) return false;

    if(dp[currentk]!=-1) return dp[currentk];

    bool iwin=false;
    for(ll i=0;i<n;i++){
        if(!ischildwin(currentk-a[i])) iwin = true;
    }
    // debug2(currentk,iwin);
    return dp[currentk]=iwin;
}


int main()
{
    fastio;
    ll i,j;
    cin>>n>>k;
    for(i=0;i<n;i++)cin>>a[i];
    for(i=0;i<=k;i++) dp[i] = -1;
    if(ischildwin(k))cout<<"First";
    else cout<<"Second";
    

    
}