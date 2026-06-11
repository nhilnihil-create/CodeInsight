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
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-9;
const ll mod=1e9+7;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

ll n,x;
vl a,b,s;

int main(){
	cin>>n>>x;
	a=vl(n);
	s=b=vl(n+1);
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i-1];
		b[i]=(i==1?4:2*i+1);
	}
	ll res=INF;
	for(int i=1;i<=n;i++){
		ll t=s[n]-s[n-i],I=1;
		for(int j=n;j>0;j-=i){
			int L=max(0,j-i),R=j;
			t+=b[I]*(s[R]-s[L]);
			if(t>=INF) break;
			I++;
		}
		res=min(res,t+i*x);
	}
	cout<<res+n*x<<endl;
}