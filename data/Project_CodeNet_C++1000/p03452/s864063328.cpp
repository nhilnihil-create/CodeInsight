#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<pair<int,int>>> edges(n);
	for(int i = 0; i < m; i++){
		int l, r, d;
		cin >> l >> r >> d;
		l--; r--;
		edges[l].emplace_back(r, d);
		edges[r].emplace_back(l, -d);
	}
	vector<int> done(n);
	vector<int> x(n);
	for(int i = 0; i < n; i++){
		if(done[i]) continue;
		done[i] = 1;
		vector<int> bfs{i};
		for(int s = 0; s < int(bfs.size()); s++){
			int v = bfs[s];
			for(auto z : edges[v]){
				int w = z.first;
				int nx = z.second + x[v];
				if(!done[w]){
					done[w] = 1;
					x[w] = nx;
					bfs.push_back(w);
				} else if(x[w] != nx){
					cout << "No" << '\n';
					exit(0);
				}
			}
		}
	}
	cout << "Yes" << '\n';
}
