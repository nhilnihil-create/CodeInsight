
// Problem : J - Sushi
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_j
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define int long long
#define db double
#define mod 1000000007
#define pb push_back
#define pp pair<int,int>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repe(i,a,b) for(int i=a;i<=b;i++)
#define repr(i,a,b) for(int i=b;i>=a;i--)
#define maxn 100005
#define ss second
#define ff first
#define all(a) a.begin(),a.end()
#define lb lower_bound
#define ub upper_bound
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
int inv(int a, int b){
 return 1<a ? b - inv(b%a,a)*b/a : 1;
}
int n,dp[105][maxn],k;
void solve()
{
	cin >> n >> k;
	vector<int> v(n);
	for(auto &x:v)
		cin >> x;
	for(int i=0;i<maxn;i++)
		dp[0][i]=1;
	for(int i=0;i<=n;i++)
		dp[i][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			dp[i][j] = dp[i-1][j];
			if(v[i-1] < j)
				dp[i][j] -= dp[i-1][j-v[i-1]-1];
			dp[i][j] = (mod+dp[i][j])%mod;
			// if(i == 1 and j == 2)
			// {
				// cout << dp[i][j] <<" "<< dp[i-1][j] <<" "<< dp[i-1][0] <<"\n";
			// }
			//cout << dp[i][j] <<" ";
		}
		//cout <<"\n";
		if(i == n)
		{
			cout << dp[n][k];
			return; 
		}
		for(int j=1;j<=k;j++)
			dp[i][j] = (dp[i][j]+dp[i][j-1])%mod;
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t=1;
    //cin >> t;
    while(t--)
    solve();
    return 0;
}
