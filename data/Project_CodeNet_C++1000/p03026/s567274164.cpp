#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

vector<vector<int>> g;
vector<ll> c;

vector<int> ans;
int idx;

void dfs(int v, int p){
	ans[v] = c[idx--];
	for(auto nv : g[v]){
		if(nv == p) continue;
		dfs(nv, v);
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	g.resize(n);
	rep(i,n-1){
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	ll sum = 0, mx = 0;
	c.resize(n);
	rep(i,n){
		cin >> c[i];
		sum += c[i];
		chmax(mx, c[i]);
	}
	cout << sum - mx << endl;
	sort(c.begin(), c.end());
	ans.resize(n);
	idx = n-1;
	dfs(0, -1);
	rep(i,n) cout << ans[i] << " ";
	cout << endl;
	return 0;
}