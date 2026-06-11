#include <bits/stdc++.h>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define REP(i,n) for(ll i=0;i<n;i++)
#define FOR(i,n1,n2) for(ll i=n1;i<n2;i++)
#define bFOR(i,n1,n2) for(ll i=n1;i>=n2;i--)
#define speed_up    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long int ll;
typedef pair<ll,ll> Pi;
typedef tuple<ll,ll,ll> Tu;
typedef tuple<ll,ll,ll> Tu;
const int INF=(ll)(1LL<<30)-1;
const double INFd=100000000000.0;
const ll INFl=(ll)9223372036854775807;
const int MAX=10000;
const ll MOD=(ll)998244353;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a, b)*b;}
int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
int mdx[8]={0,1,0,-1,1,1,-1,-1},mdy[8]={-1,0,1,0,1,-1,1,-1};


template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

ll mod_pow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1)res=res*x%MOD;
		x=x*x%MOD;
		n>>=1;
	}
	return res;
}

ll inverse_element(ll t){
	return mod_pow(t,MOD-2);
}

ll n,a,b,k;
ll c[300100];
int main(){
	cin>>n>>a>>b>>k;
	c[0]=1;
	FOR(i,0,n){
		c[i+1]=((c[i]*(n-i))%MOD)*inverse_element(i+1)%MOD;
	}
	ll ans=0;
	for(int i=0;i<=n;i++){
		if((k-a*i)%b!=0)continue;
		int j=(k-a*i)/b;
		if(j<0||j>n)continue;
		ans+=(c[i]*c[j]%MOD);
		ans%=MOD;
	}
	cout<<ans<<endl;
	return 0;
}