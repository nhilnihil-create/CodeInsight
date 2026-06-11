#include <bits/stdc++.h>
#define maxn 102333
using namespace std;
vector< pair<int, int> > G[maxn];
long long dist[maxn];
int ind[maxn];
int main() {
//	freopen("02.txt", "r", stdin);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; ++i) {
		int l, r, d;
		scanf("%d%d%d", &l, &r, &d);
		G[l].push_back(make_pair(r, d));
		++ind[r];
	}
	memset(dist, -1, sizeof dist);
	for(int i = 1; i <= n; ++i) {
		if(dist[i] == -1) {
			if(G[i].empty()) continue; // if without this bugs will occur
			if(ind[i]) continue;
			queue<int> Q;
			dist[i] = 0;
			Q.push(i);
			while(!Q.empty()) {
				int x = Q.front();
				Q.pop();
				for(auto u : G[x]) {
					if(dist[u.first] == -1) {
						dist[u.first] = dist[x] + u.second;
						Q.push(u.first);
					}
				}
			}
		}
	}
	bool valid = true;
	for(int i = 1; i <= n; ++i) {
		for(auto u : G[i]) {
			if(dist[i] + u.second != dist[u.first]) {
				valid = false;
			}
		}
	}
	puts(valid ? "Yes" : "No");
	return 0;
}