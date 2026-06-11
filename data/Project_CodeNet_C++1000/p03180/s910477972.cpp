
// Problem : 
// 			U - Grouping
// 			Editorial
// 		
// Contest : AtCoder - Educational DP Contest
// URL : https://atcoder.jp/contests/dp/tasks/dp_u
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
void solve()
{
	int n;
	cin >> n;
	int a[n][n];
	rep(i,0,n)
		rep(j,0,n)
			cin >> a[i][j];
	int dp[(1<<n)];
	memset(dp,0,sizeof(dp));
	for(int mask=1;mask<(1<<n);mask++)
	{
		vector<int> v;
		int tmp=0;
		for(int i=0;i<n;i++)
		if((mask&(1<<i)))
			v.pb(i);
		for(auto x:v)
			for(auto y:v)
				tmp+=a[x][y];
		tmp /= 2;
		for(int i=mask;i>0;i=((i-1)&mask))
			tmp = max(tmp,dp[i]+dp[mask^i]);
		dp[mask] =tmp;	
	}
	cout << dp[(1<<n)-1];
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
