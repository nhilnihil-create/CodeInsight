#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<int>> Tree(N);
	vector<int> Root(N);
	vector<int> Parent(N);
	int r = 0;
	for (int i = 0; i < N + M - 1; i++) {
		int A, B;
		cin >> A >> B;
		Tree[A - 1].push_back(B - 1);
		Root[B - 1]++;
		while (Root[r] > 0) r++;
	}
	queue<int> Q;
	Q.push(r);
	while (!Q.empty()) {
		int v = Q.front();
		Q.pop();
		for (int u : Tree[v]) {
			Root[u]--;
			if (Root[u] == 0) {
				Q.push(u);
				Parent[u] = v + 1;
			}
		}
	}
	for (int p : Parent) cout << p << endl;
}