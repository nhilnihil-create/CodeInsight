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
#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)
#define pb push_back
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)
using namespace std;
//kaewasuretyuui
typedef long long ll;
//#define int ll
typedef ll Def;
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
class UnionFind{
	public:
	vi parent;
	vi dist;
	UnionFind(int x=1){
		parent=vi(x,-1);
		dist=vi(x);
	}
	int find(int x){
		if(parent[x]<0)return x;
		int r=find(parent[x]);
		dist[x]+=dist[parent[x]];
		return parent[x]=r;
	}
	Def depth(int x){
		find(x);
		return dist[x];
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
	int size(int x){
		return -parent[find(x)];
	}
	void unite(int x,int y,Def k=0){
		k+=depth(y);
		k-=depth(x);
		k*=-1;
		x=find(x);
		y=find(y);
		if(x==y)return;
		if(size(x)<size(y)){
			swap(x,y);
			k*=-1;
		}
		parent[x]+=parent[y];
		parent[y]=x;
		dist[y]=k;
	}
	int diff(int x,int y){
		return depth(x)-depth(y);
	}
};
int main(){
	int n,q;
	cin>>n>>q;
	UnionFind uf(n);
	while(q--){
		int a,b,c;
		cin>>a>>b>>c;
		a--;b--;
		if(uf.same(a,b)){
			if(uf.diff(a,b)!=c){
				cout<<"No"<<endl;
				return 0;
			}
		}else uf.unite(a,b,c);
	}
	cout<<"Yes"<<endl;
}

