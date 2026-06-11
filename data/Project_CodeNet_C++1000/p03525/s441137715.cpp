

#include <bits/stdc++.h>
using namespace std;
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,n1,n2) for(int i=n1;i<n2;i++)
#define speed_up    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

typedef long long int ll;
typedef pair<ll,ll> Pi;
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

int n;
int d[13];
bool cclock[24];

int main(){
	cin>>n;
	REP(i,n){
		int t;
		cin>>t;
		d[min(t,24-t)]++;
	}
	d[0]++;
	REP(i,13){
		if(d[i]>=3){
			cout<<0<<endl;
			return 0;
		}
		if(d[0]>=2||d[12]>=2){
			cout<<0<<endl;
			return 0;
		}
	}
	//cout<<endl;
	cclock[0]=true;
	if(d[12])cclock[12]=true;
	bool q=false;
	for(int i=1;i<12;i++){
		if(d[i]){
			if(d[i]>1){
				cclock[i]=true;
				cclock[24-i]=true;
			}else{
				if(q)cclock[i]=true;
				else cclock[24-i]=true;
				q=!q;
			}
		}
	}
	//cout<<endl;
	int ans=24;
	for(int i=0;i<24;i++){
		for(int j=0;j<24;j++){
			if(i!=j){
				if(cclock[i]&&cclock[j]){
					ans=min(ans,abs(i-j));
					ans=min(ans,24-abs(i-j));
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}