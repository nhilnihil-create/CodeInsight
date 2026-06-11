/* ****GT_18**** */

#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define INF			100000000000000000
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
using namespace std;

#define N  404

ll n;
ll a[N];
ll dp[N][N];
ll pre[N];

ll getval(ll st, ll en){
	if(st>en)return 0;
	if(st==en)return a[st];
	return pre[en]-pre[st-1];
}

ll solve(ll st, ll en){
	if(dp[st][en]!=-1)return dp[st][en];
	if(st==en)return dp[st][en]=0;
	ll ret=INF;
	rep(i,st,en){
		ll left=0;
		if(i>st)left=solve(st,i);
		ll right=solve(i+1,en);
		ll ans = left+right;
		ans+=getval(st,i);
		ans+=getval(i+1,en);
		ret=min(ret,ans);
	}
	// cerr<<st<<" "<<en<<" "<<ret<<endl;
	return dp[st][en]=ret;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int TESTS=1;
//	cin>>TESTS;
	rep(i,0,N)rep(j,0,N)dp[i][j]=-1;	
	while(TESTS--)
	{
		cin>>n;
		rep(i,0,n)cin>>a[i+1];
		pre[1]=a[1];
		rep(i,2,n+1)pre[i]=pre[i-1]+a[i];
		cout<<solve(1,n)<<endl;
		// cout<<getval(3,4)<<endl;

	}
	return 0;
}