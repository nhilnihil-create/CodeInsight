#include <bits/stdc++.h>
using namespace std;
using Int = int_fast64_t;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	Int n, m; cin >> n >> m;
	vector<vector<Int>> g(n, vector<Int>());
	for(Int i=0; i<m; ++i){
		Int a, b; cin >> a >> b; --a; --b;
		g[a].push_back(b); g[b].push_back(a);
	}
	queue<Int> q; q.push(0);
	bool f = true;
	vector<Int> v(n, -1); v[0] = 0;
	while(!q.empty()){
		Int p = q.front(); q.pop();
		for(size_t i=0; i<g[p].size(); ++i){
			Int t = g[p][i];
			if(v[t] == v[p]){
				f = false;
				break;
			}
			if(v[t] == -1){
				v[t] = 1 - v[p];
				q.push(t);
			}
		}
		if(!f) break;
	}
	if(!f){
		cout << n * (n-1) / 2 - m << "\n";
	}else{
		Int b = count(v.begin(), v.end(), 0);
		Int w = count(v.begin(), v.end(), 1);
		cerr << b << " " << w << "\n";
		for(size_t i=0; i<v.size(); ++i) cerr << i << " " << v[i] << "\n";
		cout << b * w - m << "\n";
	}
}