#include<bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define yesno(flg) if(flg){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define MAX_N 1002
#define i197 1000000007
#define Vi vector<int>
#define Vl vector<long long>
#define pb(a) push_back(a)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P1;
typedef pair<int,int> Pi;
typedef pair<double,Pi> Pdi;
typedef pair<int,ll>Pli;
typedef pair<P1,ll> P2;
const ll INF=100000000001;
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
struct Road{double cost;int a,b;};
struct edge{int to,cost;};
struct pos{
	int x,y,cost;
};
ll a[1001],b[1001],c[1001];
ll e[1000001]={};
ll f[3000001]={};

int main() {

	int x,y,z,k;
	cin>>x>>y>>z>>k;
	rep(i,x)cin>>a[i];

	ll s=0;
	rep(j,y){
		cin>>b[j];
		rep(i,x){
			e[j*x+i]=a[i]+b[j];
			s++;
		}
	}
	sort(e,e+s,greater<ll>());
	s=0;
	rep(i,z){
		cin>>c[i];
		rep(j,k){
			f[i*k+j]=e[j]+c[i];
			s++;
		}
	}
	sort(f,f+s,greater<ll>());
	rep(i,k)cout<<f[i]<<endl;

	return 0;
}
