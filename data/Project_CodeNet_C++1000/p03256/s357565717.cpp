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

class Graph{
	private:
	int n;
	vvi g,rg;
	vi scc,used;
	stack<int> stc;
	void Order(int v){
		used[v]=1;
		for(auto u:g[v]) if(!used[u]) Order(u);
		stc.push(v);
	}
	void DFS(int v,int t){
		used[v]=1;
		for(auto u:rg[v]) if(!used[u]) DFS(u,t);
		scc[v]=t;
	}
	int SCC(){
		scc=used=vi(n);
		rg=vvi(n);
		for(int i=0;i<n;i++){
			if(!used[i]) Order(i);
			for(auto v:g[i]) rg[v].push_back(i);
		}
		int t=0;
		used=vi(n);
		while(!stc.empty()){
			int v=stc.top();
			stc.pop();
			if(!used[v]) DFS(v,t++);
		}
		return t;
	}
	public:
	Graph(int v){
		n=v;
		g=vvi(v);
	}
	void add_edge(int s,int t){
		g[s].push_back(t);
	}
	void solve(){
		int N=SCC();
		cout<<(n!=N?"Yes":"No")<<endl;
	}
};

int n,m;
string s;
vvi g;
vi a;

int main(){
	cin>>n>>m>>s;
	g=vvi(n);
	a=vi(4*n);
	Graph G(4*n);
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		u--;v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int u=0;u<n;u++) for(int v:g[u]){
		if(s[u]==s[v]){
			if(s[u]=='A') G.add_edge(u,v+n);
			else G.add_edge(u+2*n,v+3*n);
		}
		else{
			if(s[u]=='A') G.add_edge(u+n,v+2*n);
			else G.add_edge(u+3*n,v);
		}
	}
	G.solve();
}