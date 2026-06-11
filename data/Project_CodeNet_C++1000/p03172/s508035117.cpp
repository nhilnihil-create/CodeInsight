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
#define inp 100005
#define en "\n"
using namespace std;
using namespace __gnu_pbds;

signed main() 
{
    ssd
    int i,j,n,k;
	cin>>n>>k;
	vector<int> val(n+5);
	for(i=1;i<=n;i++) cin>>val[i];

	vector<vector<int>> dp(n+5, vector<int>(k+5,0));
	for(i=0;i<=n;i++) dp[i][0]=1; // If x students and no candies available
	int pre[k+5];
	
	for(i=1;i<=n;i++)
	{
		memset(pre,0,sizeof(pre));
		pre[0] = 1;
		for(j=1;j<=k;j++)
		{	
			pre[j] = pre[j-1] + dp[i-1][j];
			pre[j] %= mod;
		}
		for(j=1;j<=k;j++)
		{
			int r = j;
			int l = max(j-val[i], (int)0);
			if(l!=0) 
			{
				l--;
				dp[i][j] = pre[r] - pre[l];
			}
			else
			{
				dp[i][j] = pre[r];	
			}
			dp[i][j] = (dp[i][j] + mod) % mod;
		}
	}
	cout<<dp[n][k];
    return 0;           
}