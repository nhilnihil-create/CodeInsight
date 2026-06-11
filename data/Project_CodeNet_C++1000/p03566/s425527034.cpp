#include <bits/stdc++.h>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define REP(i,n) for(ll i=0;i<n;i++)
#define FOR(i,n1,n2) for(int i=n1;i<n2;i++)
#define bFOR(i,n1,n2) for(int i=n1;i>=n2;i--)
#define speed_up    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long int ll;
typedef pair<ll,ll> Pi;
const int INF=(ll)(1LL<<30)-1;
const double INFd=100000000000.0;
const ll INFl=(ll)9223372036854775807;
const int MAX=10000;
const ll MOD=(ll)1e9+7;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a, b)*b;}
int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
int mdx[4]={0,1,0,-1},mdy[4]={-1,0,1,0};


template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int n;
int t[110];
int v[210];
int l[110];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>t[i];
	for(int i=1;i<=n;i++)cin>>v[i];
	REP(i,110)l[i]=1e8;
	l[0]=0;
	l[n]=0;
	for(int i=0;i<100000;i++){
		for(int j=1;j<n;j++){
			l[j]=min(min(v[j],v[j+1]),min(l[j+1]+t[j+1],l[j-1]+t[j]));
		}
		for(int j=n-1;j>=0;j--){
			l[j]=min(min(v[j],v[j+1]),min(l[j+1]+t[j+1],l[j-1]+t[j]));
		}
	}
	//REP(i,n+1)cout<<l[i]<<endl;
	double ans=0;
	for(int i=1;i<=n;i++){
		if((v[i]-l[i-1])+(v[i]-l[i])<=t[i]){
			double a=t[i]-(v[i]-l[i-1])-(v[i]-l[i]);
			double tans=(double)a*v[i];
			tans+=(double)(l[i-1]+v[i])*(v[i]-l[i-1])/2;
			tans+=(double)(l[i]+v[i])*(v[i]-l[i])/2;
			ans+=tans;
		}else{
			double m=(double)(t[i]+l[i]+l[i-1])/2;
			double tans=0;
			tans+=(double)(l[i-1]+m)*(m-l[i-1])/2;
			tans+=(double)(l[i]+m)*(m-l[i])/2;
			ans+=tans;
		}
	}
	printf("%.15f",ans);
	return 0;
}