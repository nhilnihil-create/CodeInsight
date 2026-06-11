#include<bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define ff first
#define ss second
#define all(a) a.begin(), a.end()

const int mod = 1e9+7;
const int inf = 2e18;

const int maxn = 1e5+5;

vector<int> v[maxn];
int dp[maxn][2];
//0 is black,1 is white

void dfs(int node,int par)
{
	dp[node][0]=1;
	dp[node][1]=1;
	for(int i:v[node])
	{
		if(i==par)continue;
		dfs(i,node);
		dp[node][1] = (dp[node][1]*((dp[i][0]+dp[i][1])%mod))%mod;
		dp[node][0] = (dp[node][0]*(dp[i][1]%mod))%mod;
	}
}

int32_t main()
{	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin>>n;
	int m = n-1;	
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}	
	dfs(1,-1);
	cout<<(dp[1][1]+dp[1][0])%mod<<'\n';
	return 0;
}	