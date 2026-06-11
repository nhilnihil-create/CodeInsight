#include<bits/stdc++.h>
#define int			long long
#define ll 			long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (int)x.size()
#define hell        1000000007
#define rep(i,a,b)	for(int i=a;i<b;i++)
#define dep(i,a,b)	for(int i=a;i>=b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
using namespace std;

#define N  100005

ll n;
vi a[N];
bool vis[N];
ll dp[N][2];

void dfs(ll node, ll par){
	dp[node][0]=1;
	dp[node][1]=1;
	for(auto i:a[node]){
		if(i==par)continue;
		dfs(i,node);
		dp[node][0]=(dp[node][0]*(dp[i][0]+dp[i][1])%hell)%hell;
		dp[node][1]=(dp[node][1]*dp[i][0])%hell;
	}

}

void solve()
{
	cin>>n;
	rep(i,0,n-1){
		ll x,y;
		cin>>x>>y;
		a[x].pb(y);
		a[y].pb(x);
	}
	dfs(1,0);
	cout<<(dp[1][0]+dp[1][1])%hell<<endl;

}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int TESTS=1;
//	cin>>TESTS;
	while(TESTS--)
	{
		solve();
	}
	return 0;
}