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
#define inp 100005
#define en "\n"
using namespace std;
using namespace __gnu_pbds;

signed main() 
{
    ssd
    int i,j,n,k;
	cin>>n>>k;
	vector<int> v(n);
	for(int &i:v) cin>>i;

	vector<char> dp(k+5,'L');
	dp[k+1] = 'S';
	for(i=k+1;i>=2;i--)
	{
		for(j=0;j<n;j++)
		{
			if(dp[i]=='S')
			{
				if(i-v[j]>=1) dp[i-v[j]]='F'; 
			}
			else if(dp[i]=='F')
			{
				if(i-v[j]>=1 && dp[i-v[j]]!='F') dp[i-v[j]]='S'; 
			}
			else
			{
				dp[i] = 'S';
				if(i-v[j]>=1) dp[i-v[j]]='F'; 
			}
		}

	}
	if(dp[1]=='S' || dp[1]=='L') cout<<"Second";
	else cout<<"First";
    return 0;           
}