#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp> 
#include<ext/pb_ds/tree_policy.hpp> 
#define ll long long int
#define all(v) v.begin(),v.end() 
#define rev(v) v.rbegin(),v.rend()
#define ssd ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define trace(x) cerr<<#x<<" : "<<x<<endl;
#define inp 200005
#define en "\n"
using namespace std;
using namespace __gnu_pbds;

signed main() 
{
    ssd
    int i,j,k,n;
    cin>>n;
    vector<double> v(n+5);
    for(i=1;i<=n;i++) cin>>v[i];

    double dp[n+5][n+5]={};
    dp[0][0] = 1.0;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(j==0)
            {
                dp[i][0] = dp[i-1][0] * (1-v[i]);
                continue;
            }
            dp[i][j] = dp[i-1][j-1]*v[i] + dp[i-1][j]*(1-v[i]);
        }
    }
    double ans=0;
    for(i=n/2+1; i<=n; i++) ans += dp[n][i];  
    cout << fixed << setprecision(12) << ans;
    return 0;             
}