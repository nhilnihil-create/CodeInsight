// g++ -std=c++11 a.cpp
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>	
#include<map>
#include<set>
#include<utility>
#include<cmath>
#include<random>
#include<cstring>
#include<queue>
#include<stack>
#include<bitset>
#include<cstdio>
#include<sstream>
#include<iomanip>
#include<assert.h>
#include<typeinfo>
#define loop(i,a,b) for(ll i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
//#define int ll
typedef int Def;
//typedef ll Def;
typedef pair<Def,Def> pii;
typedef vector<Def> vi;
typedef vector<vi> vvi;
typedef vector<pii> vp;
typedef vector<vp> vvp;
typedef vector<string> vs;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<Def,pii> pip;
typedef vector<pip>vip;
//#define mt make_tuple
//typedef tuple<int,int,int> tp;
//typedef vector<tp> vt;
template<typename A,typename B>bool cmin(A &a,const B &b){return a>b?(a=b,true):false;}
template<typename A,typename B>bool cmax(A &a,const B &b){return a<b?(a=b,true):false;}
//template<class C>constexpr int size(const C &c){return (int)c.size();}
//template<class T,size_t N> constexpr int size(const T (&xs)[N])noexcept{return (int)N;}
const double PI=acos(-1);
const double EPS=1e-9;
Def inf = sizeof(Def) == sizeof(long long) ? 2e18 : 1e9+10;
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
class DIJ{
	public:
	struct edge{
		int to,cost;
	};
	vector<vector<edge> >G;
	int n;
	vi d;//distance
	DIJ(int size){
		n=size;
		G=vector<vector<edge> >(n);
	}
	void add_edge(int a,int b,int c){
		edge e={b,c},ee={a,c};
		G[a].pb(e);
//		G[b].pb(ee);
	}
	void dij(int s){
		d=vi(n,inf);
		d[s]=0;
		priority_queue<pii>q;
		q.push(pii(0,s));
		while(!q.empty()){
			pii p=q.top();
			q.pop();
			int pos=p.second,cost=-p.first;
			if(cost>d[pos])continue;
			rep(i,G[pos].size()){
				edge e=G[pos][i];
				int to=e.to;
				int nowcost=cost+e.cost;
				if(nowcost<d[to]){
					d[to]=nowcost;
					q.push(pii(-d[to],to));
				}
			}
		}
	}
};
int main(){
	int n;
	cin>>n;
	DIJ dij(n);
	rep(i,n){
		dij.add_edge(i,(i+1)%n,1);
		dij.add_edge(i,(i*10)%n,0);
	}
	
	dij.dij(1);
	cout<<1+dij.d[0]<<endl;
}




