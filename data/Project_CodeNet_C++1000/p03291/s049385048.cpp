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

string s;
ll pa=1;
ll a=0;
ll b=0;
ll c=0;
int main(){
	cin>>s;
	for(int i=0;i<s.size();i++){
		if(s[i]=='?'){
			c=c*3+b;
			b=b*3+a;
			a=a*3+pa;
			c%=MOD;
			b%=MOD;
			a%=MOD;
			pa*=3;
			pa%=MOD;
		}
		if(s[i]=='C'){
			c+=b;
			c%=MOD;
		}
		if(s[i]=='B'){
			b+=a;
			b%=MOD;
		}
		if(s[i]=='A'){
			a+=pa;
			a%=MOD;
		}
	}
	cout<<c<<endl;
	return 0;
}