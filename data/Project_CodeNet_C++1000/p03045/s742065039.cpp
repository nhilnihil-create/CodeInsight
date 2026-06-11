#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

struct UnionFind{
	vector<int> par,rnk;

	UnionFind(int n) : par(n), rnk(n,0){
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
			par[x] = y;
		}else{
			par[y] = x;
			if(rnk[x]==rnk[y]) rnk[x]++;
		}
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
};

int main(){
	int n,m;
	cin >> n >> m;
	UnionFind uf(n);
	REP(i,m){
		int x,y,z;
		cin >> x >> y >> z;
		uf.unite(x-1, y-1);
	}
	
	set<int> s;
	REP(i,n){
		s.insert(uf.find(i));
	}
	
	int ans = s.size();
	
	cout << ans << endl;
	
	
	
	return 0;
}