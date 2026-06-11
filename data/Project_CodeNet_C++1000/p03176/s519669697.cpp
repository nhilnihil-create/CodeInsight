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
#define INF		10000000000000
#define rep(i,a,b)	for(int i=a;i<b;i++)
#define dep(i,a,b)	for(int i=a;i>=b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
using namespace std;

#define N  200005

ll n;
ll h[N];
ll a[N];
vi bit;

ll query(ll r){
	ll ret=-INF;
	for(;r>=0;r=(r&(r+1))-1){
		ret=max(ret,bit[r]);
	}
	return ret;
}

void update(ll idx, ll val){
	for(;idx<n;idx=idx|(idx+1)){
		bit[idx]=max(bit[idx],val);
	}
}

void solve()
{
	cin>>n;
	rep(i,0,n){
		cin>>h[i];
		h[i]--;
	}	
	rep(i,0,n){
		cin>>a[i];
	}
	bit.assign(n,0);
	ll ans=0;
	rep(i,0,n){
		if(h[i]>0){
			ll curr= query(h[i]-1);
			ans=max(ans,curr+a[i]);
			update(h[i],curr+a[i]);
		}
		else{
			ans=max(ans,a[i]);
			update(h[i],a[i]);
		}
	}
	cout<<ans<<endl;
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