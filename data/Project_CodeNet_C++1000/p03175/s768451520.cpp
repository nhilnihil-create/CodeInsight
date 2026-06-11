
// Problem : 
// 			P - Independent Set
// 			Editorial
// 		
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_p
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
#define maxn 200005
#define ss second
#define ff first
#define all(a) a.begin(),a.end()
#define lb lower_bound
#define ub upper_bound
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 
int inv(int a, int b){
 return 1<a ? b - inv(b%a,a)*b/a : 1;
}
int n,dp[maxn][2];
vector<int> adj[maxn];
void dfs(int c,int p)
{
	int w = 1, b = 1;
	for(auto x:adj[c])
	{
		if(x!=p)
		{
			dfs(x,c);
			b *= dp[x][0];
			w *= (dp[x][0]+dp[x][1])%mod;
			w %= mod;
			b %=mod;
		}
	}
	dp[c][0]=w;
	dp[c][1]=b;
	return;
}
void solve()
{
	cin >> n;
	rep(i,0,n-1)
	{
		int x,y;
		cin >> x  >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs(1,0);
	cout << (dp[1][0]+dp[1][1])%mod <<"\n";
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
