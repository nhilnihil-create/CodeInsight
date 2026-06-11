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
const double PI=3.14151926535;
const ll INFl=(ll)9223372036854775807/2;
const int MAX=10000;
const ll MOD=(ll)1e9+7;
const ll tMOD=(ll)998244353;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a, b)*b;}
//int dx[4]={0,-1,0,1},dy[4]={-1,0,1,0};
int mdx[8]={0,1,0,-1,1,1,-1,-1},mdy[8]={-1,0,1,0,1,-1,1,-1};


template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int n;
string ss[100010];
int main(){
	cin>>n;
	cout<<0<<endl;
	string s,t;
	cin>>s;
	if(s=="Vacant"){
		return 0;
	}
	cout<<n/2<<endl;
	cin>>t;
	if(t=="Vacant"){
		return 0;
	}
	ss[0]=s;
	ss[n]=s;
	ss[n/2]=t;
	int l,r;
	if(((s==t)^((n/2)%2==0))){
		l=0;
		r=n/2;
	}else{
		l=n/2;
		r=n;
	}
	for(int zz=0;zz<18;zz++){
		int lr=(l+r)/2;
		cout<<lr<<endl;
		string newt;
		cin>>newt;
		ss[lr]=newt;
		if(newt=="Vacant")return 0;
		if(!((lr-l)%2==0^(newt==ss[l]))){
			l=lr;
		}else{
			r=lr;
		}
	}
	return 0;
}