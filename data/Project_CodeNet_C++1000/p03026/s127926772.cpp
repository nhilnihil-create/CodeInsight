#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DFS(vector<vector<int>>& Tree, vector<int>& C, vector<int>& D, int di, int& ci) {
	if (D[di] > 0) return;
	D[di] = C[ci];
	ci++;
	for (int dj : Tree[di]) DFS(Tree, C, D, dj, ci);
};

int main() {
	int N;
	cin >> N;
	vector<vector<int>> Tree(N);
	vector<pair<int, int>> Edges(N - 1);
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		Tree[a - 1].push_back(b - 1);
		Tree[b - 1].push_back(a - 1);
		Edges[i] = { a - 1,b - 1 };
	}
	vector<int> C(N), D(N,-1);
	for (int i = 0; i < N; i++) cin >> C[i];
	sort(C.begin(), C.end(), greater<int>());
	int ci = 0;
	DFS(Tree, C, D, 0, ci);
	int sum = 0;
	for (auto& p : Edges) sum += min(D[p.first],D[p.second]);
	cout << sum << endl;
	for (int d : D) cout << d << " ";
	cout << endl;
}