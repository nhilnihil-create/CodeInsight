#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
using ll = long long;

const int nax = 1e5 + 5;
vector<int> edges[nax];

const int mod = 1e9 + 7;
int mul(int a, int b) {
	return (ll) a * b % mod;
}

pair<int,int> dfs(int current, int pre) {
	int presently_white = 1, presently_black = 1;
	for (auto each : edges[current]) {
		if (each != pre) {
			auto other_tree = dfs(each, current);

			presently_white = mul(presently_white, (other_tree.first + other_tree.second) % mod);

			presently_black = mul(presently_black, other_tree.first);
		}
	}

	return make_pair(presently_white, presently_black);
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	pair<int,int> p = dfs(1, -1); //from 1 to endless
	int answer = (p.first + p.second) % mod;
	printf("%d\n", answer);
	return 0;
}