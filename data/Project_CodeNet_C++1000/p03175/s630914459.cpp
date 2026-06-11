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

struct Node{
	vector<int> con;
	int ab,aw;
}g[100010];

void go(int n,int p){
	g[n].ab=1; g[n].aw=1;
	for(auto &i:g[n].con){
		if(i==p) continue;
		go(i,n);
		g[n].ab=g[n].ab* g[i].aw         %MOD;
		g[n].aw=g[n].aw*(g[i].aw+g[i].ab)%MOD;
	}
}

int32_t main() {
	INIT();
	//code...
	int n; cin>>n;
	int s,t;
	For(i,1,n-1){
		cin>>s>>t;
		s--; t--;
		g[s].con.eb(t);
		g[t].con.eb(s);
	}
	go(0,0);
	cout<<(g[0].ab+g[0].aw)%MOD<<"\n";
	return 0;
}