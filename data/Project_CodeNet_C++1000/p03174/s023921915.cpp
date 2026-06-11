//checking brute2
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

const ll N=21;
ll n,a[N][N],dp[1<<N];

ll solve(ll men_index,ll selected_women)
{
    if(men_index==n){
        if(selected_women == (1LL<<n)-1) return 1;
        return 0;
    }
    if(dp[selected_women]!=-1) return dp[selected_women];
    ll count=0;
    for(ll i=0;i<n;i++)
        if(a[men_index][i] && !(selected_women & (1LL<<i)))
            count = (count+solve(men_index+1,selected_women | (1LL<<i)) )%MOD;
    return dp[selected_women]=count;
}


int main()
{
    fastio;
    cin>>n;
    for(ll j=0;j<(1<<n);j++) dp[j]  = -1;
    for(ll i=0;i<n;i++)for(ll j=0;j<n;j++)cin>>a[i][j];
    cout<<solve(0,0);


    
}
