#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<ll,ll>;
#define For(i,a,b)  for(int i=a;i<=b;i++)
#define Forr(i,a,b) for(int i=a;i>=b;i--)
#define F first
#define S second
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define bpc __builtin_popcount
#define MOD (ll)(1e9+7)
#define INF (1e18)
#define EPS (1e-6)
#define NATHANLEE_IS_EVIL_AND_ELECTRIC true
#define int ll
#ifdef LOCAL_TEST
#define debug(...) do{\
	cerr<<__PRETTY_FUNCTION__<<" - "<<__LINE__<<\
	" : ("#__VA_ARGS__<<") = ";\
	_OUT(__VA_ARGS__);\
}while(0)
template<typename T>void _OUT(T x){cerr<<x<<"\n";}
template<typename T,typename...I>void _OUT(T x,I ...tail){cerr<<x<<", ";_OUT(tail...);}
#else
#define debug(...)
#endif
void INIT(){
#ifdef LOCAL_TEST
	freopen("D:\\input.in","r",stdin);
	freopen("D:\\output.out","w",stdout);
	freopen("D:\\error.out","w",stderr);
#endif
	ios::sync_with_stdio(!NATHANLEE_IS_EVIL_AND_ELECTRIC);
	cin.tie(0);
}

ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }
ll lcm(ll a,ll b) { return a/gcd(a,b)*b; }
ll fpow(ll b,ll p){
	b%=MOD;
	ll ans=1;
	while(p>0){
		if(p&1) ans=(ans*b)%MOD;
		p/=2;
		b=(b*b)%MOD;
	}
	return ans;
}

int a[16][16];
int dp[70000];
int s[70000];

int32_t main() {
	INIT();
	//code...
	int n; cin>>n;
	For(i,0,n-1) For(j,0,n-1) cin>>a[i][j];
	For(mask,0,(1<<n)-1){
		s[mask]=0;
		For(i,0,n-2) For(j,i+1,n-1)
			if(mask&(1<<i) && mask&(1<<j)) s[mask]+=a[i][j];
	}
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	For(mask,1,(1<<n)-1){
		dp[mask]=-INF;
		for(int m=mask;m>0;m=(m-1)&mask){
			dp[mask]=max(dp[mask],dp[mask^m]+s[m]);
		}
	}
	cout<<dp[(1<<n)-1]<<"\n";
	return 0;
}