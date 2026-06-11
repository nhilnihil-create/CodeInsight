#include <bits/stdc++.h>
using namespace std;using ll=long long;using uint=unsigned int;using pii=pair<int,int>;using pll=pair<ll,ll>;using ull = unsigned long long;using ld=long double;template<typename T>void _(const char*s,T h){cerr<<s<<" = "<<h<<"\n";}template<typename T,typename...Ts>void _(const char*s,T h,Ts...t){int b=0;while(((b+=*s=='(')-=*s==')')!=0||*s!=',')cerr<<*s++;cerr<<" = "<<h<<",";_(s+1,t...);}// break continue pop_back 998244353
#define int ll
#define pii pll
#define f first
#define s second
#define pb emplace_back
#define forn(i,n) for(int i=0;i<(n);++i)
#define sz(a)((int)(a).size())
#define sqr(x) ((x)*(x))
struct init{init(){cin.tie(0);iostream::sync_with_stdio(0);cout<<fixed<<setprecision(10);cerr<<fixed<<setprecision(5);}~init(){
#ifdef LOCAL
#define dbg(...) _(#__VA_ARGS__,__VA_ARGS__)
cerr<<"Time elapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";
#else
#define dbg(...) 
#endif
}}init;template<typename T,typename U>void upx(T&x,U y){if(x<y)x=y;}template<typename T,typename U>void upn(T&x,U y){if(x>y)x=y;}mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());const int D=4,dx[]={+1,0,-1,0},dy[]={0,+1,0,-1};
const int N=5050,OO=1e18;
int dp[N][N];
int a[N],w[N];
int32_t main(){

	int n,A,B;
	cin>>n>>A>>B;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		w[a[i]]=i;
	}
	for(int i=0;i<=n+1;++i)for(int j=0;j<=n+1;++j)dp[i][j]=OO;
	dp[0][0]=0;
	for(int i=0;i<=n;++i)
		for(int j=0;j<=n;++j)
		{
			if(w[j+1]<=i)upn(dp[i][j+1],dp[i][j]);
			else upn(dp[i][j+1],dp[i][j]+B);
			if(a[i+1]<=j)upn(dp[i+1][j],dp[i][j]);
			else upn(dp[i+1][j],dp[i][j]+A);
			if(a[i+1]==j+1)upn(dp[i+1][j+1],dp[i][j]);
		}
	int ans=OO;
	forn(i,n+1)upn(ans,dp[i][n]);
	cout<<ans<<'\n';

    return 0;
}
