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

int n,q;
string s;
char t[200100],d[200100];
int ans=0;
int main(){
	cin>>n>>q;
	cin>>s;
	REP(i,q)cin>>t[i]>>d[i];
	int lb=-1,ub=n;
	while(ub-lb>1){
		int flag=0;
		int mid=(lb+ub)/2;
		int now=mid;
		for(int i=0;i<q;i++){
			if(t[i]==s[now]){
				if(d[i]=='L'){
					now--;
				}else{
					now++;
				}
			}
			if(now==-1){
				flag=1;
				break;
			}
			if(now==n){
				break;
			}
		}
		if(flag){
			lb=mid;
		}else{
			ub=mid;
		}
	}
	ans+=lb+1;
	lb=-1,ub=n;
	while(ub-lb>1){
		int flag=0;
		int mid=(lb+ub)/2;
		int now=mid;
		for(int i=0;i<q;i++){
			if(t[i]==s[now]){
				if(d[i]=='L'){
					now--;
				}else{
					now++;
				}
			}
			if(now==n){
				flag=1;
				break;
			}
			if(now==-1){
				break;
			}
		}
		if(flag){
			ub=mid;
		}else{
			lb=mid;
		}
	}
	//cout<<ub;
	ans+=(n-ub);
	cout<<n-ans<<endl;
	return 0;
}