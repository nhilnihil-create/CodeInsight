#include <bits/stdc++.h>
#define int long long
using namespace std;

struct UnionFind{
	vector<int> par,gsize;
	int sz;
	
	UnionFind(int N) : par(N) ,gsize(N), sz(N) {
		for(int i=0;i<N;i++) {
			par[i]=i;
			gsize[i]=1;
		}
	}
	
    //root:子xの根を返す
	int root(int x){
		if(par[x]==x) return x;
		else{
			return par[x]=root(par[x]); 
		}
	}
	
    //unite:要素xとyを結ぶ
	void unite(int x,int y){
		int rx=root(x);
		int ry=root(y);
		if(rx==ry) return;
		else {
			if(gsi(rx)>gsi(ry))swap(rx,ry);
			par[ry]=rx; sz--; 
			gsize[rx]+=gsize[ry];
		}
	}
	
    //same:要素xとyの親が同じか判定する
	bool same(int x,int y){
		int rx=root(x);
		int ry=root(y);
		return rx==ry;
	}
	
    //size:全体のグループの数を返す
	int size() { return sz; }

	//gsize:要素xが属するグループの大きさを返す
	int gsi(int x) {return gsize[root(x)]; }
};

signed main(){
	int N,M; cin>>N>>M;
	vector<int> p(N);
	for(int i=0;i<N;i++){cin>>p[i]; p[i]--;}
	UnionFind tree(N);
	for(int i=0;i<M;i++){
		int x,y; cin>>x>>y; x--; y--;
		tree.unite(x,y);
	}
	int ans=0;
	for(int i=0;i<N;i++){
		ans+=tree.same(i,p[i]);
	}
	cout<<ans<<endl;

}