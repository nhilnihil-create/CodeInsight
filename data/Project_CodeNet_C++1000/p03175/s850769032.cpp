// youngjinp20
// 2020 07

#include <bits/stdc++.h>
#define by(x) [](const auto& a, const auto& b) { return a.x < b.x; }
#define byr(x) [](const auto& a, const auto& b) { return a.x > b.x; }
#define smax(a, b) ((a) < (b) ? ((a)=(b), true) : false)
#define smin(a, b) ((a) > (b) ? ((a)=(b), true) : false)
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pa;

const int MAX = 1e5;
const int MOD = 1e9+7;
int N;
vector<int> G[MAX+1];

pa dfs(int v, int from) {
	queue<pa> values;
	for (auto e : G[v]) {
		if (e == from) continue;
		values.push(dfs(e, v));
	}

	ll b=1, w=1;
	while (!values.empty()) {
		auto x = values.front();
		values.pop();
		b *= x.second;
		b %= MOD;
		w *= x.first + x.second;
		w %= MOD;
	}

	return {b, w};
};

int main() {
	cin >> N;

	for (int i=1; i<N; i++) {
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}

	pa ret = dfs(1, 0);
	cout << (ret.first + ret.second) % MOD << endl;

	return 0;
}
