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
    int i,j,k,n,m;
    cin>>n>>m;
    vector<string> v(n+5);
    for(i=1;i<=n;i++) {cin>>v[i]; v[i]="0"+v[i];}
    
    ll dp[n+5][m+5]={};
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(i==1 && j==1) {dp[i][j]=1; continue;}
            if(v[i][j]!='#')
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
                dp[i][j] %= mod;
            }
        }
    }
    cout<<dp[n][m];
    return 0;             
}