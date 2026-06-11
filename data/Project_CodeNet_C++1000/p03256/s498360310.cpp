//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const ll mod = 1e9 + 7;
int n, m, col[500200], t = 0;
string s;
vvi g;
void dfs(int v) {
	sort(all(g[v]));
	g[v].erase(unique(all(g[v])), g[v].end());
	col[v] = 1;
	for(auto i : g[v]) {
		if(col[i]==1)
			cout << "Yes", exit(0);
		if(col[i]) continue;
		dfs(i);
	}
	col[v] = 2;
}
int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> s;
	g.resize(2*n);
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t, f--, t--;
		f*=2, t*=2;
		if(s[f>>1] == s[t>>1]) {
			g[f].pb(t+1);
			if(f!=t)
			g[t].pb(f+1);
		} else {
			g[f+1].pb(t);
			g[t+1].pb(f);
		}
	}
	for(int i = 0; i < 2*n; i++) {
		if(col[i]) continue;
		dfs(i);
	}
	cout << "No";
}
