#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > G;
vector<int> color;
long long b,w;

bool isBipartite(int v, int prev,int c) {
	color[v]=c;
	++(c==0?b:w);
	for(auto e:G[v]) {
		if(e==prev) continue;
		if(color[e]==c) return false;
		if(color[e]!=-1) continue;
		if(!isBipartite(e,v,1-c)) return false;
	}
	return true;
}

int main() {
	long long n,m; cin >> n >> m;
	G.resize(n);
	color.assign(n,-1);
	for(int i=0;i<m;++i) {
		int a,b; cin >> a >> b;
		--a, --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	if(isBipartite(0,-1,0)) cout << b*w-m << endl;
	else cout << n*(n-1)/2-m << endl;
	
	return 0;
}
