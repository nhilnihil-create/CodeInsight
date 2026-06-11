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

ll n;
vpll a;
vl s;
vvl g;

ll dfs(ll v,ll p,ll d){
	ll res=d;
	for(auto u:g[v]) if(u!=p) res+=dfs(u,v,d+1);
	return res;
}

int main(){
	cin>>n;
	a=vpll(n);
	s=vl(n,1);
	g=vvl(n);
	for(int i=0;i<n;i++){
		ll x;
		cin>>x;
		a[i]={x,i};
	}
	sort(a.begin(),a.end());
	for(int i=n-1;i>0;i--){
		ll d=a[i].first,t=d+2*s[i]-n;
		ll id=lower_bound(a.begin(),a.end(),pll(t,0))-a.begin();
		if(id>=i||a[id].first!=t){
			cout<<-1<<endl;
			return 0;
		}
		ll u=a[i].second,v=a[id].second;
		s[id]+=s[i];
		g[u].push_back(v);
		g[v].push_back(u);
	}
	if(dfs(a[0].second,-1,0)==a[0].first){
		for(int u=0;u<n;u++) for(auto v:g[u]) if(u<v) cout<<u+1<<' '<<v+1<<endl;
	}
	else cout<<-1<<endl;
}