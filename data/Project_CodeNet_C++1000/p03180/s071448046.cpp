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
#define INF			LLONG_MAX
#define rep(i,a,b)	for(int i=a;i<b;i++)
#define dep(i,a,b)	for(int i=a;i>=b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
using namespace std;

#define N  17

ll n;
ll a[N][N];
ll pre[(1ll<<N)];
ll dp[1LL<<N];


ll calc(ll mask){
	if(mask==0)return 0;
	if(dp[mask]!=-1LL)return dp[mask];
	dp[mask]=-INF;
	for(ll i=mask;i>0;i=(i-1)&mask){
		ll remask = mask^i;
		dp[mask]=max(dp[mask],calc(remask)+pre[i]);
	}
	// cerr<<"mask:"<<mask<<" val:"<<dp[mask]<<endl;
	return dp[mask];
}


void solve()
{
	cin>>n;
	rep(i,0,n){
		rep(j,0,n){
			cin>>a[i][j];
		}
	}
	for(ll i=0;i<(1ll<<n);i++){
		for(ll j=0;j<n;j++){
			for(ll k=j+1;k<n;k++){
				if(i&(1LL<<j) && i&(1LL<<k))
					pre[i]=pre[i]+	a[j][k];	
			}
		}
		// cerr<<"i: "<<i<<" pre:"<<pre[i]<<endl;
	}
	memset(dp,-1LL,sizeof(dp));
	cout<<calc((1LL<<n)-1)<<endl;

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