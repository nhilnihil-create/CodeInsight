#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
const ll mod = 1000000007;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, d;
vvi g;
int dfs(int v = 1, int p = 1) {
	int x = 0, y = 0;
	for(auto i : g[v]) {
		if(i == p) continue;
		int t = 1+dfs(i, v);
		if(x<t)y=x,x=t;
		else if(y<t) y = t;
	}
	d = max(d, x+y);
	return x;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	g.resize(n+1);
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	dfs();
	cout << (((d-1)%3)?"First":"Second");
	return 0;
}
