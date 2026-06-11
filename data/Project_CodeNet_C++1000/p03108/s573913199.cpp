#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct UnionFind{
	vector<ll> rnk,par,num;
	UnionFind(ll N) : rnk(N),par(N),num(N){
		init();
	}
	void init(){
		for(ll i = 0;i < rnk.size();i++){
			rnk[i] = 0;
			par[i] = i;
			num[i] = 1;
		}
	}
	ll find(ll x){
		if(par[x] == x) return x;
		return par[x] = find(par[x]);
	}
	void unite(ll x,ll y){
		x = find(x);
		y = find(y);
		if(x == y) return;
		if(rnk[x] < rnk[y]){
			par[x] = y;
			num[y] += num[x];
		}
		else{
			par[y] = x;
			num[x] += num[y];
			if(rnk[x] == rnk[y]) rnk[x]++;
		}
	}
	bool same(ll x,ll y){
		return (find(x) == find(y));
	}
	ll size(ll x){
		return num[find(x)];
	}
};

signed main(){
 ll n, m; cin >> n >> m;
 vector<ll> a(m), b(m);
 for(int i = 0; i < m; i++){
   cin >> a[i] >> b[i]; --a[i]; --b[i];
 }
 UnionFind tree(n);
 vector<ll> ans(m);
 ll num = n * (n - 1) / 2;
 for(ll i = m - 1; i >= 0; i--){
   ans[i] = num;
   ll x = a[i], y = b[i];
   if(!tree.same(x, y)){
     num -= tree.size(x) * tree.size(y);
   }
   tree.unite(x, y);
 }
  for(ll i : ans) cout << i << endl;
}
