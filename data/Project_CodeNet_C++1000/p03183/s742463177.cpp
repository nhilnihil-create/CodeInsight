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

const int M=20005;
ll n;
vip a;

int main(){
	cin>>n;
	a=vip(n);
	for(int i=0;i<n;i++){
		ll x,y,z;
		cin>>x>>y>>z;
		a[i]={x+y,{x,z}};
	}
	sort(a.begin(),a.end());
	vl dp(M);
	ll res=0;
	for(int i=0;i<n;i++){
		P p=a[i].second;
		ll x=a[i].first,y=p.first,z=p.second;
		for(int j=x-y;j>=0;j--) dp[j+y]=max(dp[j+y],dp[j]+z);
	}
	for(int i=0;i<M;i++) res=max(res,dp[i]);
	cout<<res<<endl;
}