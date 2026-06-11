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

class Graph{
	private:
	int n;
	vvp g;
	public:
	vi DIJ(int s){
		priority_queue<P> q;
		vi d(n,inf);
		d[s]=0;
		q.push({0,s});
		while(!q.empty()){
			P p=q.top();
			q.pop();
			int v=p.second;
			if(d[v]<-p.first) continue;
			for(auto i:g[v]){
				int u=i.first,D=d[v]+i.second;
				if(d[u]>D){
					d[u]=D;
					q.push({-D,u});
				}
			}
		}
		return d;
	}
	Graph(int v){
		n=v;
		g=vvp(v);
	}
	void add_edge(int s,int t,int c){
		g[s].push_back({t,c});
		g[t].push_back({s,c});
	}
};

int n;

int main(){
	cin>>n;
	Graph g(n);
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g.add_edge(u-1,v-1,1);
	}
	vi d=g.DIJ(0);
	int M=-1,v;
	for(int i=0;i<n;i++) if(d[i]>M) M=d[i],v=i;
	d=g.DIJ(v);
	M=-1;
	for(auto i:d) M=max(M,i);
	cout<<(M%3==1?"Second":"First")<<endl;
}