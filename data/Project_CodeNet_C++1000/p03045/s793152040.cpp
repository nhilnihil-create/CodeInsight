#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<int>>& Tree, vector<int>& Traced, int now) {
	if (Traced[now]) return;
	Traced[now] = 1;
	for (int v : Tree[now]) if (!Traced[v]) DFS(Tree, Traced, v);
}

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> Tree(N);
	for (int i = 0; i < M; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		Tree[x - 1].push_back(y - 1);
		Tree[y - 1].push_back(x - 1);
	}
	vector<int> Traced(N);
	int ans = 0, first=0;
	while (first < N) {
		DFS(Tree, Traced, first);
		ans++;
		while (first < N && Traced[first]) first++;
	}
	cout << ans << endl;
}