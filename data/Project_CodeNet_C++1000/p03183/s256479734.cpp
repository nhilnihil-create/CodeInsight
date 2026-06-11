#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
const int INF=2012345678;
const ll LLINF=4012345678012345678LL;
const ll MOD=1000000007; //998244353; //
const ld PI=3.1415926535898;
const ld EPS=1e-9;
ll gcd(ll a,ll b){if(a<b)swap(a,b);if(b==0)return a;return gcd(b,a%b);}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
inline ll expo(ll b,ll p,ll m){ll res=1; while(p){if(p&1)res=(res*b)%m; b=(b*b)%m; p>>=1;} return res;}
inline ll modinv(ll a,ll m){return expo(a,m-2,m);}

int main(){
	int n;
	scanf("%d",&n);
	pair<ii,ii> p[n];
	for(int i=0;i<n;i++){
		scanf("%lld%lld%lld",&p[i].fi.se,&p[i].se.fi,&p[i].se.se);
		p[i].fi.fi=p[i].fi.se+p[i].se.fi;
	}
	ll dp[20005];memset(dp,0,sizeof(dp));
	ll ans=0;
	sort(p,p+n);
	for(int i=0;i<n;i++){
		for(int j=p[i].fi.fi;j>=p[i].fi.se;j--){
			dp[j]=max(dp[j],dp[j-p[i].fi.se]+p[i].se.se);
			ans=max(ans,dp[j]);
		}
	}
	printf("%lld",ans);
}
