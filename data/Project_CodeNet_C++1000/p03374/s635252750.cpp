//	ZapZu's code hohoho
//	#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define dfs_black 1
#define dfs_white -1
#define pr pair
#define vt vector
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef double db;
typedef long long li;
typedef long double ld;

typedef pr<int, int> ii;
typedef pr<ld,ld> dd;

typedef vt<int> vi;
typedef vt<li> vli;
typedef vt<ld> vld;
typedef vt<ii> vii;

typedef map<int, int> mii;
typedef map<int, bool> mib;
typedef map<int, char> mic;

typedef set<int> s_i;
typedef set<char> s_c;

const int MOD = 1e9+7;
const li INF = 1e18;
const ld PI = 4*atan((ld)1);
int n, c;
int solve(int x[], int v[])
{
	int ans=0;
	int dp[n+1];
	int curr=0;
	for(int i=n+1; i>=1; i--)
	{
		if(i<=n) curr+=v[i];
		if(i==n+1) dp[i]=0;
		else dp[i]=max(dp[i+1], curr-(c-x[i]));
//		cout<<dp[i]<<" ";
	}
	curr=0;
	for(int i=0; i<=n; i++)
	{
		if(i) curr+=v[i];
		ans=max(ans, curr-2*x[i]+dp[i+1]);
	}
	return ans;
}
signed main()
{
//	freopen(".inp", "r", stdin);
//	freopen(".out", "w", stdout);
	cin>>n>>c;
	int x[n+1], v[n+1];
	x[0]=v[0]=0;
	for(int i=1; i<=n; i++)
	{
		cin>>x[i]>>v[i];
	}
	int ans=solve(x, v);
	for(int i=1; i<=n; i++)
	{
		x[i]=c-x[i];
	}
	reverse(x+1, x+n+1);
	reverse(v+1, v+n+1);
	ans=max(ans, solve(x, v));
	cout<<ans;
}


