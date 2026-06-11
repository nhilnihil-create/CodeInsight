#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, A[1 << 18], B[1 << 18], dist[1 << 18];
vector<int> G[1 << 18];

void dfs(int pos, int dep) {
	if (dist[pos] != (1 << 30)) return;
	dist[pos] = dep;
	for (int i = 0; i < G[pos].size(); i++) dfs(G[pos][i], dep + 1);
}

int diameter() {
	for (int i = 1; i <= N; i++) dist[i] = (1 << 30);
	dfs(1, 0);
	int maxn = -1, maxid = -1;
	for (int i = 1; i <= N; i++) { if (maxn < dist[i]) { maxn = dist[i]; maxid = i; } }

	for (int i = 1; i <= N; i++) dist[i] = (1 << 30);
	dfs(maxid, 0);
	int ret = 0;
	for (int i = 1; i <= N; i++) ret = max(ret, dist[i]);
	return ret;
}

int main() {
	cin >> N;
	for (int i = 1; i <= N - 1; i++) {
		cin >> A[i] >> B[i];
		G[A[i]].push_back(B[i]);
		G[B[i]].push_back(A[i]);
	}
	int dst = diameter();
	if (dst % 3 == 1) cout << "Second" << endl;
	else cout << "First" << endl;
	return 0;
}