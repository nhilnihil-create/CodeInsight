#include<bits/stdc++.h>
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
using namespace std;

template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

struct LowLink {
	const vector<vector<ll>>& g;
	vector< ll > used, ord, low;
	vector< ll > articulation;
	vector< pair< ll, ll > > bridge;

	LowLink(const vector<vector<ll>>& g) : g(g) {}

	ll dfs(ll idx, ll k, ll par) {
		used[idx] = true;
		ord[idx] = k++;
		low[idx] = ord[idx];
		bool is_articulation = false;
		ll cnt = 0;
		for (auto& to : g[idx]) {
			if (!used[to]) {
				++cnt;
				k = dfs(to, k, idx);
				low[idx] = min(low[idx], low[to]);
				is_articulation |= ~par && low[to] >= ord[idx];
				if (ord[idx] < low[to]) bridge.emplace_back(minmax(idx, (ll)to));
			}
			else if (to != par) {
				low[idx] = min(low[idx], ord[to]);
			}
		}
		is_articulation |= par == -1 && cnt > 1;
		if (is_articulation) articulation.push_back(idx);
		return k;
	}

	void build() {
		used.assign(g.size(), 0);
		ord.assign(g.size(), 0);
		low.assign(g.size(), 0);
		int k = 0;
		for (int i = 0; i < g.size(); i++) {
			if (!used[i]) k = dfs(i, k, -1);
		}
	}
};

int main() {
	ll n, m;
	cin >> n >> m;
	vector<vector<ll>> graph(n);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	LowLink link(graph);
	link.build();
	cout << link.bridge.size() << endl;
	return 0;
}
