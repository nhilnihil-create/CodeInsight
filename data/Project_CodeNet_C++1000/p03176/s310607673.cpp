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

#define LO(x) (x&(-x))
struct BIT{
	int a[200020];
	int n;
	void init(int _n){
		n=_n;
		memset(a,0,sizeof(a));
	}
	void mod(int i,int x){
		while(i<=n){
			a[i]=max(a[i],x);
			i+=LO(i);
		}
	}
	int ask(int i){
		int ans=0;
		while(i>0){
			ans=max(ans,a[i]);
			i-=LO(i);
		}
		return ans;
	}
}bit;

int h[200020];
int b[200020];

int32_t main() {
	INIT();
	//code...
	int n; cin>>n;
	bit.init(n);
	For(i,0,n-1) cin>>h[i];
	For(i,0,n-1) cin>>b[i];
	int ans=0;
	For(i,0,n-1){
		b[i]+=bit.ask(h[i]-1);
		ans=max(ans,b[i]);
		bit.mod(h[i],b[i]);
	}
	cout<<ans<<"\n";
	return 0;
}