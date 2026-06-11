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
vector<int> ans;
int main(){
	cin>>n;
	if(n<=5){
		if(n==3){
			cout<<"2 5 63"<<endl;
		}else if(n==4){
			cout<<"2 5 20 63"<<endl;
		}else{
			cout<<"2 3 4 6 9"<<endl;
		}
		return 0;
	}
	ll co=0;
	ll n4;
	ll n6;
	for(int i=0;i<n;i++){
		if(i%4==0){
			ans.push_back(i/4*6+2);
			co=co+i/4*6+2;
		}else if(i%4==1){
			ans.push_back(i/4*6+3);
			co=co+i/4*6+3;
		}else if(i%4==2){
			ans.push_back(i/4*6+4);
			co=co+i/4*6+4;
			n4=i/4*6+10;
		}else{
			ans.push_back(i/4*6+6);
			co=co+i/4*6+6;
			n6=i/4*6+12;
		}
	}
	if(co%6==0){
		REP(i,ans.size()){
			cout<<ans[i]<<" ";
		}
	}else if(co%6==2){
		REP(i,ans.size()){
			if(ans[i]==8)continue;
			cout<<ans[i]<<" ";
		}
		cout<<n6;
	}else if(co%6==3){
		REP(i,ans.size()){
			if(ans[i]==9)continue;
			cout<<ans[i]<<" ";
		}
		cout<<n6;
	}else{
		REP(i,ans.size()){
			if(ans[i]==9)continue;
			cout<<ans[i]<<" ";
		}
		cout<<n4;
	}
	cout<<endl;
	return 0;
}