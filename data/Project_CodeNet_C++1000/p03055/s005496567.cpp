#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> ii;
bool det(int d) {
	if(d == 0) return true;
	return (d%3) != 1;
}
vvi g;
ii dm(int u,int p) {
	ii res = {0,u};
	for(int i=0;i<g[u].size();i++) {
		int v = g[u][i];
		if(v == p) continue;
		ii dv = dm(v,u);
		dv.first++;
		if(dv.first > res.first) {
			res = dv;
		}
	}
	return res;
}
int main() {
	ios::sync_with_stdio(0);cin.tie(0);
	int n;
	cin >> n;
	g.assign(n,vi());
	for(int i=0;i<n-1;i++) {
		int a,b;
		cin >> a >> b;a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	ii fv = dm(0,-1);
	ii sv = dm(fv.second,-1);
	if(det(sv.first)) {
		cout << "First\n";
	} else {
		cout << "Second\n";
	}
}