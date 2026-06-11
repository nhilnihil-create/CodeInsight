#include <algorithm>
#include <cmath>
#include <vector>
#include <functional>
#include <cstdlib>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <ctype.h>
#include <climits>
#include <queue>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

struct UnionFind{
	vector<int> par,rnk,numele;

	UnionFind(int n) : par(n), rnk(n,0), numele(n,1){
		REP(i,n){
			par[i] = i;
		}
	}
	
	int find(int x){
		if(par[x]==x){
			return x;
		}else{
			return par[x]=find(par[x]);
		}
	}
	void unite(int x, int y){
		x = find(x);
		y = find(y);
		if(x==y) return;
		if(rnk[x] < rnk[y]){
			numele[y] += numele[x];
			par[x] = y;
		}else{
			numele[x] += numele[y];
			par[y] = x;
			if(rnk[x]==rnk[y]) rnk[x]++;
		}
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
	int count(int x){
		return numele[find(x)];
	}
};

int main(){
	int n,m;
	cin >> n >> m;
	vector<int> a(m),b(m);
	for(int i=m-1; i>=0; i--){
		cin >> a[i] >> b[i];
		a[i]--; b[i]--;
	}
	UnionFind uf(n);
	vector<ll> ans(m);
	ans[0] = (ll)n*(n-1)/2;
	REP(i,m-1){
		if(uf.same(a[i],b[i])){
			ans[i+1] = ans[i];
		}else{
			ll diff = (ll)uf.count(a[i])*(ll)uf.count(b[i]);
			uf.unite(a[i],b[i]);
			ans[i+1] = ans[i]-diff;
		}
	}
	
	for(int i=m-1; i>=0; i--) cout << ans[i] << endl;
	
	return 0;
}