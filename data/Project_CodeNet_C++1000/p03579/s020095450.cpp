#include"bits/stdc++.h"
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
using ll = long long;

bool dfs(vector<vector<ll>>& node,vector<ll> &color, ll v, ll cor) {
	color[v] = cor;
	for (auto next_v : node[v]) {
		if ((color[next_v] != -1)) {
			if (color[next_v] == cor)return false;
			continue;
		}

		if (!dfs(node, color, next_v, !cor))return false;
	}
	return true;
}

int main() {
	ll n, m, a, b;;
	map<ll, ll>mp;
	a = b = n = m = 0;
	cin >> n >> m;
	vector<vector<ll>>node(n);
	vector<ll>color(n, -1);
	rep(i, m) {
		cin >> a >> b;
		a--, b--;
		node[a].push_back(b);
		node[b].push_back(a);
	}

	if (!dfs(node,color, 0LL, 0LL)) cout << ((n * (n - 1)) / 2) - m << endl;
	else {
		for (int c : color) {
			mp[c]++;
		}
		cout << mp[0] * mp[1] - m << endl;
	}
	return 0;
}
