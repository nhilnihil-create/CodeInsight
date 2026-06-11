#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
const int maxn = 1<<18, rt = 1<<10;
map<int, int> pos;
int n, m, l, r, d;
vector<pair<int, ll>> g[maxn];
void add(int l, int r, int d) {
	g[l].pb({r, d});
	g[r].pb({l, -d});
}
bool dfs(int v) {
	int ok = 1;
	for(auto &_i : g[v]) {
		int i = _i.first, d = _i.second;
		if(pos.count(i)) ok &= pos[i]-pos[v] == d;
		else pos[i] = pos[v] + d, ok &= dfs(i);
	}
	return ok;
}
bool check() {
	int ok = 1;
	for(int i = 1; i <= n; i++) if(!pos.count(i)) pos[i] = 0, ok &= dfs(i);
	return ok;
}
int solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) g[i].clear();
	pos.clear();
	while(m--) {
		cin >> l >> r >> d;
		add(l, r, d);
	}
	cout << (check()?"Yes":"No") << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	solve();
}
