#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back
 
typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef unsigned long long ull;
typedef long double ld; 
typedef tree<ii, null_type, less<ii>, rb_tree_tag, tree_order_statistics_node_update> pbds;

int a[(1<<18)+18];
ii dp[(1<<18)+18][2];

void upd(int u, int v)
{
	vector<ii> V;
	V.pb(dp[u][0]);V.pb(dp[u][1]);V.pb(dp[v][0]);V.pb(dp[v][1]);
	sort(V.begin(),V.end()); V.erase(unique(V.begin(),V.end()),V.end());
	reverse(V.begin(),V.end());
	dp[u][0]=V[0]; dp[u][1]=V[1];
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	for(int i=0;i<(1<<n);i++) cin>>a[i];
	for(int i=0;i<(1<<n);i++) dp[i][0]=dp[i][1]=mp(-int(1e9),-int(1e9));
	for(int i=0;i<(1<<n);i++)
	{
		dp[i][0]=mp(a[i],i);
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j)) upd(i,i^(1<<j));
		}
	}
	int ans=0;
	for(int i=1;i<(1<<n);i++)
	{
		ans=max(ans,dp[i][0].fi+dp[i][1].fi);
		cout<<ans<<'\n';
	}
}
