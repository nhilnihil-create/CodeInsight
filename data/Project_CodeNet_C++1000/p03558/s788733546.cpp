#include <bits/stdc++.h>
typedef long long ll; 
 
using namespace std;
using P = pair<ll, ll>;

struct edge { int to, cost; };
vector<vector<edge>> G;
vector<ll> d;

void dijkstra(int s) {
	priority_queue<P, vector<P>, greater<P> > que;
	d[s] = 0;
	que.push(P(0, s));

	while (!que.empty()) {
		P p = que.top();
		que.pop();
		int v = p.second;
		if (d[v] < p.first) { continue; }

		for (int i = 0; i < G[v].size(); ++i) {
			edge e = G[v][i];
			if (d[e.to] > d[v] + e.cost) {
				d[e.to] = d[v] + e.cost;
				que.push(P(d[e.to], e.to));
			}
		}
	}
}

int main() {
	const ll INF = 1e18;
	int K;
	cin >> K;

	G.resize(K);
	d.resize(K, INF);

	for (int i = 0; i < K; ++i) {
		int to1 = (i + 1) % K;
		int to10 = (i * 10) % K;

		if (to1 != i) { G[i].push_back({to1, 1}); }
		if (to10 != i) { G[i].push_back({to10, 0}); }
	}

	dijkstra(1);

	ll res = d[0] + 1;
	cout << res << endl;

	return 0;
}
