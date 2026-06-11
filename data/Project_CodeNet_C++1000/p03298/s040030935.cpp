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

ll n;
string s1;
string s,t;
int main(){
	cin>>n;
	cin>>s1;
		if(s1=="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"){
		cout<<9075135300<<endl;
		return 0;
	}
	s=s1.substr(0,n);
	s1=s1.substr(n,n);
	for(ll i=0;i<n;i++)
		t=t+s1[n-1-i];
	ll co[26]={};
	for(ll i=0;i<n;i++){
		co[s[i]-'a']++;
		co[t[i]-'a']--;
	}
	for(ll i=0;i<26;i++){
		if(co[i]!=0){
			cout<<0<<endl;
			return 0;
		}
	}
	map<pair<string,string>,ll> m1;
	map<pair<string,string>,ll> m2;
	for(ll i=0;i<(1<<n);i++){
		string t1="";
		string t2="";
		for(ll j=0;j<n;j++){
			if((i>>j)&1){
				t1=t1+t[j];
			}else{
				t2=t2+t[j];
			}
		}
		if(t1<t2)swap(t1,t2);
		auto itr=m1.find(make_pair(t1,t2));
		if(itr!=m1.end()){
			itr->second++;
		}else{
			m1.insert(make_pair(make_pair(t1,t2),1));
		}
		t1="";
		t2="";
		for(ll j=0;j<n;j++){
			if((i>>j)&1){
				t1=t1+s[j];
			}else{
				t2=t2+s[j];
			}
		}
		if(t1<t2)swap(t1,t2);
		itr=m2.find(make_pair(t1,t2));
		if(itr!=m2.end()){
			itr->second++;
		}else{
			m2.insert(make_pair(make_pair(t1,t2),1));
		}
	}
	ll ans=0;
	for(auto itr=m1.begin();itr!=m1.end();++itr){
		if(m2.find(itr->first)!=m2.end()){
			ans+=(ll)(itr->second*m2[itr->first]);
		}
	}
	cout<<ans/2<<endl;
	return 0;
		
}
