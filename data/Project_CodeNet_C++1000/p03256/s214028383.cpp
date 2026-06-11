#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const double EPS = 1e-10;
vector<int> G[400000];
int vis[400000];
bool dfs(int v) {
	if (vis[v] == 1) return 0;
	if (vis[v] == 2) return 1;
	vis[v] = 1;
	for (int to : G[v]) {
		if (!dfs(to)) return 0;
	}
	vis[v] = 2;
	return 1;
}
int main() {
	int N, M;
	cin >> N >> M;
	string s;
	cin >> s;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		if (s[a] == s[b]) {
			G[a * 2].push_back(b * 2 + 1);
			G[b * 2].push_back(a * 2 + 1);
		}
		else {
			G[a * 2 + 1].push_back(b * 2);
			G[b * 2 + 1].push_back(a * 2);
		}
	}
	bool ok = 0;
	for (int i = 0; i < N; i++) {
		if (vis[i]) continue;
		if (!dfs(i)) {
			ok = 1;
			break;
		}
	}
	if (ok) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}