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

int main()
{
    fastio;
    int n;
    cin>>n;
    vector<ll>a(n),pre(n);
    vector<vector<ll>>dp(n,vector<ll>(n));
    
    cin>>a[0];
    pre[0]=a[0];
    for(ll i=1;i<n;i++){
        cin>>a[i];
        pre[i] =a[i]+pre[i-1];
    }

    //dp[i][j] = minimum total cost of combining interval [i,x] and [x+1,j] into [i,j]
    // dp[i][j] = min(dp[i][x]+dp[x+1][j]) + sum_of_interval[i,j]

    for(ll i=n-1;i>=0;i--)
    {
        dp[i][i] = 0; //base case
        for(ll j=i+1;j<n;j++)
        {
            dp[i][j] = LLONG_MAX;
            for(ll x=i;x<j;x++)  dp[i][j] = min(dp[i][j],dp[i][x] + dp[x+1][j]);
            dp[i][j] += pre[j] - (i?pre[i-1]:0); //current combining cost;
        }
    }
    cout<<dp[0][n-1];



    
}
