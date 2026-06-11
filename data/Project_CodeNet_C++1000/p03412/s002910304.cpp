#include <bits/stdc++.h>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<P,int> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1000000000000000000;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=1e9+7;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

int n;
vl a,b,c;

int f(ll l,ll r){
	return lower_bound(c.begin(),c.end(),r)-lower_bound(c.begin(),c.end(),l);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	a=b=c=vl(n);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	ll res=0;
	for(int i=0;i<30;i++){
		ll A=1<<i;
		for(int j=0;j<n;j++) c[j]=b[j]%(A*2);
		sort(c.begin(),c.end());
		int t=0;
		for(int j=0;j<n;j++){
			ll N=a[j]%(A*2);
			(t+=f(A-N,A*2-N)+f(3*A-N,4*A-N))%=2;
		}
		res+=(1<<i)*t;
	}
	cout<<res<<endl;
}