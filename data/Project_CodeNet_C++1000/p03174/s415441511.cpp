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

#define N  22

ll n;
bool a[N][N];
ll dp[N][1ll<<21];

ll calc(ll men, ll mask){
	if(mask==0)return 1;
	if(dp[men][mask]!=-1)return dp[men][mask];
	ll temp=mask;
	ll shift=0;
	ll ans=0;
	while(temp>0){
		bool bit = temp&1;
		if(bit){
			if(a[men][shift+1]){
				ll newmask = mask^(1ll<<shift);
				ans=(ans+calc(men-1,newmask))%hell;	
			}
		}
		temp>>=1;
		shift++;
	}
	return dp[men][mask]=ans;
}


void solve()
{
	cin>>n;
	rep(i,1,n+1){
		rep(j,1,n+1){
			cin>>a[i][j];
		}
	}
	memset(dp,-1LL,sizeof(dp));
	cout<<calc(n,(1ll<<n)-1)<<endl;
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