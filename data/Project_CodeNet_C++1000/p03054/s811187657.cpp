#include <bits/stdc++.h>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,n1,n2) for(int i=n1;i<n2;i++)
#define bFOR(i,n1,n2) for(int i=n1;i>=n2;i--)
#define speed_up    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long int ll;
typedef pair<int,int> Pi;
const int INF=(ll)(1LL<<31)-1;
const ll INFl=(ll)9223372036854775807;
const int MAX=10000;
const ll MOD=(ll)1e9+7;
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a, b)*b;}
//int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

int h,w,n;
int sr,sc;
string s,t;

int main(){
	cin>>h>>w>>n;
	cin>>sr>>sc;
	sr--,sc--;
	cin>>s>>t;
	int ans=1;
	int tsr=sr,tsc=sc;
	//R
	for(int i=0;i<n;i++){
		if(s[i]=='R')sc++;
		if(sc>=w){
			ans=0;
			break;
		}
		if(t[i]=='L'&&sc!=0)sc--;
	}
	sr=tsr,sc=tsc;
	//L
	for(int i=0;i<n;i++){
		if(s[i]=='L')sc--;
		if(sc<0){
			ans=0;
			break;
		}
		if(t[i]=='R'&&sc!=w-1)sc++;
	}
	sr=tsr,sc=tsc;
	//U
	for(int i=0;i<n;i++){
		if(s[i]=='U')sr--;
		if(sr<0){
			ans=0;
			break;
		}
		if(t[i]=='D'&&sr!=h-1)sr++;
	}
	sr=tsr,sc=tsc;
	//D
	for(int i=0;i<n;i++){
		if(s[i]=='D')sr++;
		if(sr>=h){
			ans=0;
			break;
		}
		if(t[i]=='U'&&sr!=0)sr--;
	}				
	if(ans)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}