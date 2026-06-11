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

ll n,k;
ll a[1010];
ll b[1010];
vector<ll> C;
vector<ll> D;
int main(){
	cin>>n>>k;
	REP(i,n)cin>>a[i];
	b[0]=0;
	for(ll i=1;i<=n;i++){
		b[i]=b[i-1]+a[i-1];
	}
	for(ll i=0;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			C.push_back(b[j]-b[i]);
		}
	}
	sort(C.begin(),C.end());
	ll ans=0;
	for(ll i=42;i>=0;i--){
		ll t1=pow(2,i);
		for(ll j=0;j<C.size();j++){
			if(C[j]>=t1&&C[j]-t1==(C[j]^t1)){
				D.push_back(C[j]);
			}
		}
		if(D.size()>=k){
			C.clear();
			ans+=t1;
			REP(j,D.size()){
				C.push_back(D[j]);
			}
			D.clear();
			/*cout<<t1<<endl;
			REP(j,C.size()){
				cout<<C[j]<<endl;
			}
			cout<<endl;*/
		}else{
			D.clear();
			//cout<<i<<endl;
		}
	}
	cout<<ans<<endl;
	return 0;
}