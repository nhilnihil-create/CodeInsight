#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size();
using ll = long long;
const int N = 1e5;

int n, m;
vector<int> conn[N];
bitset<N> valid;

int out[N], cnt[N], parent[N];

queue<int> q;

void search() {
	queue<int> nxt;
	vector<bool> used(N, false);
		
	int found = 0;
	while (found != n) {
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			++found;
			used[v] = true;
			
			for (int u : conn[v]) {
				if (used[u]) continue;
				++cnt[u];
				if (cnt[u] == out[u]) {
					nxt.push(u);
				}
			}
		}
		
		while (!nxt.empty()) {
			int v = nxt.front();
			nxt.pop();
			q.push(v);
			for (int u : conn[v]) {
				if (used[u] && !parent[u]) {
					parent[u] = v;
				}
			}
		}
	}
}


int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	valid.set();
	cin >> n >> m;
	for (int i = 0; i < n - 1 + m; ++i) {
		int a, b;
		cin >> a >> b;
		conn[a].push_back(b);
		conn[b].push_back(a);
		++out[a];
		valid[a] = 0;
	}
	
	for (int i = 1; i <= n; ++i) {
		if (valid[i]) {
			q.push(i);
		}
	}
	
	search();
	for (int i = 1; i <= n; ++i) {
		cout << parent[i] << '\n';
	}
}
