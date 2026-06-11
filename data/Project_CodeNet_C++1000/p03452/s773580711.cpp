#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <chrono>
#include <tuple>
#include <random>
#include <cmath>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 1e6 * 2 + 10, INF = 1e9 * 1e9 + 10;

ll dsu[SIZE], dist[SIZE], sz[SIZE];

bool fl = true;
vector<vector<pair<ll, ll>>> gr;
vector<ll> tps;
ll used[SIZE];

ll col[SIZE];

void dfs(int v) {
	col[v] = 1;

	for (auto to : gr[v]) {
		if (!col[to.first]) {
			dfs(to.first);
		}
		else if (col[to.first] == 1) {
			fl = false;
		}
	}

	col[v] = 2;
	tps.push_back(v);
}

void check(int v) {
	used[v] = 1;

	for (auto to : gr[v]) {
		if (!used[to.first]) {
			dist[to.first] = dist[v] + to.second;
			check(to.first);
		}
		else if (dist[to.first] != dist[v] + to.second) {
			fl = false;
		}
	}
}
int main()
{
	fastInp;

	ll n, m;
	cin >> n >> m;

	gr.resize(n);
	for (int i = 0; i < m; i++) {
		ll l, r, d;
		cin >> l >> r >> d;
		l--; r--;
		gr[l].push_back({ r, d });
	}

	for (int i = 0; i < n; i++) {
		if (!col[i]) dfs(i);
	}

	reverse(tps.begin(), tps.end());

	for (auto cur : tps) {
		if (!used[cur]) {
			check(cur);
		}
	}
	if (fl) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
	return 0;
}