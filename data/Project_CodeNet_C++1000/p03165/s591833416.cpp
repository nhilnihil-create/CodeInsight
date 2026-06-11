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

int dp[3010][3010];
char src[3010][3010];

int32_t main() {
	INIT();
	//code...
	string s,t; cin>>s>>t;
	For(i,0,sz(s)-1) For(j,0,sz(t)-1){
		if(s[i]==t[j]){
			if(i==0 || j==0) dp[i][j]=1;
			else dp[i][j]=dp[i-1][j-1]+1;
		}else if(i==0 && j==0){
			dp[i][j]=0;
		}else if(i==0){
			src[i][j]='L';
			dp[i][j]=dp[i][j-1];
		}else if(j==0){
			src[i][j]='U';
			dp[i][j]=dp[i-1][j];
		}else{
			if(dp[i-1][j]>dp[i][j-1]){
				src[i][j]='U';
				dp[i][j]=dp[i-1][j];
			}else{
				src[i][j]='L';
				dp[i][j]=dp[i][j-1];
			}
		}
	}
	int a=sz(s)-1,b=sz(t)-1;
	string ans;
	while(a>=0 && b>=0){
		if(s[a]==t[b]){
			ans=s[a]+ans;
			a--; b--;
		}else if(src[a][b]=='L'){
			b--;
		}else{
			a--;
		}
	}
	cout<<ans<<"\n";
	return 0;
}