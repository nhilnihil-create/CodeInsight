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
#define INF (2e9)
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

double pos[3010][3010]; //first i with j head

int32_t main() {
	INIT();
	//code...
	int n; cin>>n;
	memset(pos,0,sizeof(pos));
	pos[0][0]=1;
	For(i,1,n){
		double p; cin>>p;
		pos[i][0]=pos[i-1][0]*(1-p);
		For(j,1,n) pos[i][j]=pos[i-1][j]*(1-p)+pos[i-1][j-1]*p;
	}
	double ans=0;
	For(i,n/2+1,n) ans+=pos[n][i];
	cout<<fixed<<setprecision(15)<<ans<<"\n";
	return 0;
}