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

ll n;
ll c[200100];
vector<ll> cc[200100];
ll dp[200100];
bool excl[200100];
int main(){
	cin>>n;
	FOR(i,1,n+1){
		cin>>c[i];
		if(c[i-1]!=c[i]){
			cc[c[i]].push_back(i);
		}else{
			excl[i]=1;
		}
	}
	dp[0]=1;
	dp[1]=1;
	dp[2]=1;
	for(ll i=3;i<=n;i++){
		dp[i]=dp[i-1];
		auto itr=lower_bound(cc[c[i]].begin(),cc[c[i]].end(),i);
		if(itr==cc[c[i]].begin())continue;
		if(excl[i])continue;
		itr--;
		dp[i]=dp[i-1]+dp[*itr];
		dp[i]%=MOD;
		//cout<<i<<" "<<dp[i]<<endl;
	}
	cout<<dp[n]<<endl;
	return 0;
}