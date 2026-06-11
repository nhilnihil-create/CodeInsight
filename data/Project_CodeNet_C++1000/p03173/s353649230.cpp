#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp> 
#include<ext/pb_ds/tree_policy.hpp> 
#define int long long int
#define all(v) v.begin(),v.end() 
#define rev(v) v.rbegin(),v.rend()
#define ssd ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define ordered_set tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define trace(x) cerr<<#x<<" : "<<x<<endl;
#define en "\n"
using namespace std;
using namespace __gnu_pbds;
#define inp 200005

//dp[i][j] = min cost to combine range (i,j)
signed main() 
{
    ssd
    int i,j,k,n;
    cin>>n;
    vector<int> val(n+5);
    for(i=1;i<=n;i++) cin>>val[i];

    vector<vector<int>> dp(n+5, vector<int>(n+5,1e18+5));
    vector<int> pre(n+5,0);
    for(i=1;i<=n;i++)
    {
        pre[i] = pre[i-1] + val[i];
    }
    for(int l=n; l>=1; l--)
    {
        for(int r=l; r<=n; r++)
        {
            if(l==r) dp[l][r] = 0;
            else
            {
                for(i=l; i<r; i++)
                {
                    int sum = pre[r]-pre[l-1];
                    dp[l][r] = min(dp[l][i] + dp[i+1][r] + sum, dp[l][r]);
                }
            }
        }
    }
    cout<<dp[1][n];
    return 0;           
}