#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
const double PI = 3.141592653589793238;
const double EPS = 1e-10;
typedef pair<int, int> P;
vector<int> G[100000];
int cnt[100000];
int dist[100000];
void dfs(int v, int p, int d) {
	dist[v] = d;
	for (int to : G[v]) {
		if (to == p) continue;
		dfs(to, v, d + 1);
	}
}
int main() {
	int N;
	cin >> N;
	map<ll, int> idx;
	vector<ll> D;
	for (int i = 0; i < N; i++) {
		ll d;
		cin >> d;
		idx[d] = i;
		D.push_back(d);
	}
	sort(D.begin(), D.end());
	for (int i = 0; i < N; i++) cnt[i] = 1;
	vector<P> edge;
	for (int i = N - 1; i > 0; i--) {
		int v = idx[D[i]];
		ll X = D[i] + cnt[v] * 2 - N;
		if (idx.find(X) == idx.end()) {
			cout << -1 << endl;
			return 0;
		}
		int u = idx[X];
		G[u].push_back(v);
		G[v].push_back(u);
		cnt[u] += cnt[v];
		edge.emplace_back(u, v);
	}
	int v = idx[D[0]];
	dfs(v, -1, 0);
	ll sum = 0;
	for (int i = 0; i < N; i++) {
		sum += dist[i];
	}
	if (sum != D[0]) {
		cout << -1 << endl;
		return 0;
	}
	for (int i = 0; i < N - 1; i++) {
		cout << edge[i].first + 1 << " " << edge[i].second + 1 << endl;
	}
}