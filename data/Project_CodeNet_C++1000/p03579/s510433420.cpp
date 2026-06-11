#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
typedef long long int ll;

struct UnionFind{
    vector<int> par,num;
    vector<bool> done;
    UnionFind(int n):par(n),num(n,1),done(n,false){
        iota(par.begin(),par.end(),0);  //include<numeric>
    }
    int find(int v){
        return (par[v]==v)?v:(par[v]=find(par[v]));
    }
    void unite(int u,int v){
        u=find(u),v=find(v);
        if(u==v)return;
        if(num[u]<num[v])swap(u,v);
        num[u]+=num[v];
        par[v]=u;
        done[u]=done[u]|done[v];
    }
    bool same(int u,int v){
        return find(u) == find(v);
    }
    bool ispar(int v){
        return v=find(v);
    }
    int size(int v){
        return num[find(v)];
    }
};

int main(){
	ll n,m; cin >> n >> m;
	UnionFind uf(2*n);
	for(int i=0;i<m;i++){
		int a,b; cin >> a >> b;
		a--; b--;
		uf.unite(a,b+n);
		uf.unite(a+n,b);
	}
	if(uf.same(0,n)){ //二部グラフでない場合
		ll ans=n*(n-1)/2-m;
		cout << ans << endl;
	}
	else{
		ll cnt=0;
		for(int i=0;i<n;i++){
			if(uf.same(0,i)){
				cnt++;
			}
		}
		ll ans=cnt*(n-cnt)-m;
		cout << ans << endl;
	}
}