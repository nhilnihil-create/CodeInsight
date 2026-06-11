#pragma GCC optimize("O4")
#include <bits/stdc++.h>
#define For(i,a,b) for(int i=a;i<=b;i++)
#define F first
#define S second
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define MOD (ll)(1e9+7)
#define INF (9e18)
#define int ll
#define EPS (1e-6)
#define DB(x) #x<<":"<<x<<" "
#define debug(...) do{\
	cerr<<__PRETTY_FUNCTION__<<" - "<<__LINE__<<\
	" : ("#__VA_ARGS__<<") = ";\
	_OUT(__VA_ARGS__);\
}while(0)
using namespace std;
using ll=long long;
using pii=pair<int,int>;
template<typename T>void _OUT(T x){cerr<<x<<endl;}
template<typename T,typename...I>void _OUT(T x,I ...tail){cerr<<x<<", ";_OUT(tail...);}

void INIT(){
#ifdef LOCAL_TEST
	freopen("D:\\input.in","r",stdin);
	freopen("D:\\output.out","w",stdout);
	freopen("D:\\error.out","w",stderr);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
}

int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }
int lcm(int a,int b) { return a/gcd(a,b)*b; }
int fpow(int b,int p){
	b%=MOD;
	int ans=1;
	while(p>0){
		if(p&1) ans=(ans*b)%MOD;
		p/=2;
		b=(b*b)%MOD;
	}
	return ans;
}

int a[100010];
pii b[100010];
int c[100010];

int32_t main() {
	INIT();
	//code...
	int n,m; cin>>n>>m;
	For(i,0,n-1) cin>>a[i];
	For(i,0,m-1) cin>>b[i].S>>b[i].F;
	sort(a,a+n); reverse(a,a+n);
	sort(b,b+m); reverse(b,b+m);
	int tot=0;
	int i=0;
	for(;tot<n && i<m;i++){
		b[i].S=min(b[i].S,n-tot);
		tot+=b[i].S;
	}
	i--;
	For(j,0,n-1){
		if(j<n-tot) c[j]=0;
		else{
			c[j]=b[i].F;
			b[i].S--;
			if(b[i].S==0) i--;
		}
	}
	int ans=0;
	For(j,0,n-1) ans+=max(a[j],c[j]);
	cout<<ans<<"\n";
	return 0;
}
