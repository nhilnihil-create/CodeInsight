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

string s;
int main(){
	cin>>s;
	if(!(s[0]=='1'&&s[s.size()-2]=='1'&&s[s.size()-1]=='0')){
		cout<<-1<<endl;
		return 0;
	}
	for(int i=1;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-2-i]){
			cout<<-1<<endl;
			return 0;
		}
	}
	int t=s.size()/2;
	for(int i=s.size()/2-1;i>=0;i--){
		cout<<i+1<<" "<<t+1<<endl;
		if(s[i]=='1'){
			t=i;
		}
	}
	for(int i=s.size()/2+1;i<s.size();i++){
		cout<<s.size()/2+1<<" "<<i+1<<endl;
	}
	return 0;
}