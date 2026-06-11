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
const ll INF=1ll<<55;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=1e9+7;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

ll n,L,R;
vl a;

int main(){
	cin>>n>>R>>L;
	a=vl(n);
	for(auto &i:a) cin>>i;
	if(L<R){
		swap(L,R);
		reverse(a.begin(),a.end());
		for(int i=0;i<n;i++) a[i]=n-a[i]+1;
	}
	vl dp(n+1,INF);
	dp[0]=0;
	for(int i=0;i<n;i++){
		ll x=a[i];
		vl DP(n+1,INF);
		DP[0]=0;
		for(int j=0;j<x;j++) DP[x]=min(DP[x],dp[j]);
		for(int j=0;j<=n;j++) if(j!=x) DP[j]=dp[j]+(j<x?R:L);
		dp=DP;
	}
	ll res=INF;
	for(int i=0;i<=n;i++) res=min(res,dp[i]);
	cout<<res<<endl;
}