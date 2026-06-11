#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>
#define fileopen(filename) if (fopen(filename".INP", "r")) {freopen(filename".INP", "r", stdin);freopen(filename".OUT", "w", stdout);}
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define rep(i,n) for (int i=1;i<=n;++i)
#define eb emplace_back
#define pb push_back
#define memset(a,i) memset(a,i,sizeof(a))
#define upper(v,a) upper_bound(v.begin(), v.end(), a)
#define lower(v,a) lower_bound(v.begin(), v.end(), a)
#define ii pair<int,int>
#define fi first
#define se second
#define endl '\n'
#define gcd __gcd
const int maxn=1e5+1;
const int INF=1e9+1;

signed main()
{
	fastio;
	int n;cin>>n;
	int a[3][n+1];
	rep(i,2)rep(j,n)cin>>a[i][j];
	int dp[3][n+1];
	dp[1][1]=a[1][1];dp[2][0]=0;
	for (int i=2;i<=n;++i)dp[1][i]=dp[1][i-1]+a[1][i];
	for (int i=1;i<=n;++i)dp[2][i]=max(dp[2][i-1],dp[1][i])+a[2][i];
	cout<<dp[2][n];
}