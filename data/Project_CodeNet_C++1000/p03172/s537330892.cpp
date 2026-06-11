#include <bits/stdc++.h> //M - Candies
#define f first
#define s second
#define pb push_back
#define all(x) x.begin(),x.end()
using namespace std;
const int maxn = 110;
const int maxm = 1e5 + 7;
const int mod = 1e9 + 7;

typedef long long int ll;

// ll dp[maxn][maxm];
ll dp[maxm],v[maxn],k;
ll pre[maxm];

int n,m;
inline ll go(int a,int b)
{
	if(a < 0) a = 0;

	if(a == 0) return pre[b]%mod;
	return (pre[b] - pre[a-1])%mod;
}

//dp[i][j] == na poss 'i' usando 'j' candies

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
		
	cin>>n>>k;
	for(int i=1;i<=n;++i) cin>>v[i];

	dp[0] = 1;
	
	for(int i=1;i<=n;++i)
	{
		
		pre[0] = dp[0];
		dp[0] = 0;

		for(int j=1;j<=k;++j)
			pre[j] = (dp[j] + pre[j-1])%mod;

		for(int j = 0; j <= k;++j)
			dp[j] = go(j-v[i],j);
	}

	
			
	// for(int j=0;j<=v[n];++j)
	// 	ans = (ans + dp[n][j])%mod;
	
	// cout<<ans<<"\n";
	if(dp[k] < 0) dp[k] += mod;
	
	cout<<dp[k]<<"\n";	
}