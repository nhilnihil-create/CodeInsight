#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const ll INF = 1LL << 60;
typedef pair<int, int> P;
vector<int> G[200000];
P dfs(int v, int p) {
	P ret(0, v);
	for (int to : G[v]) {
		if (to == p) continue;
		P tmp = dfs(to, v);
		ret = max(ret, P(tmp.first + 1, tmp.second));
	}
	return ret;
}
int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int s = dfs(0, -1).second;
	int d = dfs(s, -1).first;
	if (d % 3 == 1) cout << "Second" << endl;
	else cout << "First" << endl;
}