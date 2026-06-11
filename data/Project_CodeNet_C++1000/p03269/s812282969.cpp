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
const ll MOD=(ll)1e9+7;
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

ll L;
Tu ans[65];
int m=0,n=0;
int main(){
	cin>>L;
	int r;
	for(int i=0;i<=19;i++){
		if(mod_pow(2,i)<=L){
			r=i;
			//cout<<mod_pow(2,i)<<endl;
		}
	}
	n=r+1;
	for(int i=1;i<r+1;i++){
		ans[m]=Tu(i,i+1,0);
		m++;
		ans[m]=Tu(i,i+1,(ll)(mod_pow(2,i-1)));
		m++;
	}
	
	for(int t=n-1;t>=1;t--){
		if(L-mod_pow(2,t-1)>=mod_pow(2,r)){
			ans[m]=Tu(t,n,L-mod_pow(2,t-1));
			L-=mod_pow(2,t-1);
			m++;
		}
	}
	cout<<n<<" "<<m<<endl;
	REP(i,m){
		cout<<get<0>(ans[i])<<" "<<get<1>(ans[i])<<" "<<get<2>(ans[i])<<endl;
	}
	return 0;
}