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
typedef pair<ll,pll> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-9;
const ll mod=1e9+7;
const int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

int n;
vvi g;
vi a,d;

int main(){
	cin>>n;
	a=d=vi(n);
	g=vvi(n);
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		g[u].push_back(v);
		g[v].push_back(u);
		d[u]++;d[v]++;
	}
	queue<int> q;
	for(int i=0;i<n;i++) if(d[i]==1) q.push(i);
	for(auto &i:a) cin>>i;
	sort(a.begin(),a.end());
	int S=0;
	vi res(n);
	for(int i=0;i<n-1;i++){
		int v=q.front();q.pop();
		res[v]=a[i];
		S+=a[i];
		for(auto u:g[v]) if(d[u]){
			d[u]--;
			if(d[u]==1) q.push(u);
		}
	}
	for(int i=0;i<n;i++) if(!res[i]) res[i]=a[n-1];
	cout<<S<<endl;
	for(int i=0;i<n;i++) cout<<res[i]<<" \n"[i==n-1];
}