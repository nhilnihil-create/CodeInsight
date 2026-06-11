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
#define debug2(x, y) cout << #x << " = " << x << "   " << #y << " = " << y << "=>";
#define debugarray(arr,n,x) { cout << "[" ; for(ll i=0;i<n;i++) cout<<arr[i]<<" "; cout<<"] , "<<#x<<" = "<<x<<'\n';}

const ll N=401;
ll a[N],pre[N];
ll dp[N][N];
ll solve(ll start,ll end)
{
    if(start==end) return 0;
    if(dp[start][end]!=-1) return dp[start][end]; 
    ll current_min=LLONG_MAX;
    for(ll i=start;i<end;i++)
        current_min = min(current_min,solve(start,i)+solve(i+1,end));
    
    current_min += pre[end] - (start>0 ? pre[start-1] : 0 );
    // debug2(start,end);
    // debug1(current_min);
    return dp[start][end]=current_min;
}
int main()
{
    fastio;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)for(int j=0;j<n;j++)dp[i][j]=-1;
    for(int i=0;i<n;i++) cin>>a[i];
    pre[0]=a[0];
    for(ll i=1;i<n;i++) pre[i]=a[i]+pre[i-1];
    ll mincost = solve(0,n-1);
    cout<<mincost;



    
}
