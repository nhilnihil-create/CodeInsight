#include <iostream>
#include <fstream>
#include <cassert>
#include <typeinfo>
#include <vector>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cstdio>
#include <queue>
#include <iomanip>
#include <cctype>
#include <random>
#include <complex>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<long double,long double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<long double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vb> vvb;
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
	vvp g;
	public:
	int DIJ(int s,int t){
		priority_queue<P> q;
		vi d(n,inf);
		d[s]=0;
		q.push({0,s});
		while(!q.empty()){
			P p=q.top();
			q.pop();
			int v=p.second;
			if(d[v]<-p.first) continue;
			for(int i=0;i<g[v].size();i++){
				int F=g[v][i].first,S=g[v][i].second;
				if(d[F]>d[v]+S){
					d[F]=d[v]+S;
					q.push({-d[F],F});
				}
			}
		}
		return d[t];
	}
	Graph(int v){
		n=v;
		g=vvp(v);
	}
	void add_edge(int s,int t,int c){
		g[s].push_back({t,c});
	}
};

int n;

int main(){
	cin>>n;
	Graph g(n);
	for(int i=0;i<n;i++) for(int j=0;j<10;j++){
		g.add_edge(i,(i*10+j)%n,j);
	}
	int res=inf;
	for(int i=1;i<min(10,n);i++) res=min(res,g.DIJ(i,0)+i);
	cout<<res<<endl;
}