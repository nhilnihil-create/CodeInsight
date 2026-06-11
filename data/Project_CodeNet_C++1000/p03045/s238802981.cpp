#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);++i)
#define ALL(v)   (v).begin(),(v).end()
#define debug(x) cerr<<#x<<": "<<(x)<<endl
#define INF      (int)1e9
#define EPS      (double)1e-9
#define MOD      ((int)1e9+7)
using namespace std;
typedef long long     llong;
typedef vector<int>   vi;
typedef vector<vi >   vvi;
typedef vector<vvi >  vvvi;
typedef pair<int,int> pii;
template<class Type> void line(const Type &a){int cnt=0;for(const auto &elem:a){if(cnt++)cerr<<' ';cerr<<elem;}cerr<<endl;}

struct UnionFind{
	vi par;		//par[i]:=(0以上の場合iの親. 0未満の場合はiを含むグループのサイズ).
	int num;	//num:=(グループの数).
	
	UnionFind(int n):par(n,-1),num(n){}//Constructor.
	
	void init(){fill(ALL(par),-1), num=par.size();}
	int root(int x){return (par[x]<0)?x:par[x]=root(par[x]);}//Recrusion.
	int size(int x){return -par[root(x)];}
	bool same(int x,int y){return root(x)==root(y);}
	bool unite(int x,int y){
		x=root(x), y=root(y);
		if(x==y) return false;//Do nothing.
		if(size(x)<size(y)) swap(x,y);//Merge technique(x<-y).
		par[x]+=par[y];
		par[y]=x;
		num--;
		return true;
	}
};

int main(){
	int n,m;
	cin>>n>>m;
	
	UnionFind uf(n);
	REP(i,m){
		int x,y,z;
		cin>>x>>y>>z;
		x--, y--;
		uf.unite(x,y);
	}
	
	cout<<uf.num<<endl;
}