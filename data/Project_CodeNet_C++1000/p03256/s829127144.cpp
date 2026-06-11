#include <queue>
#include <vector>
#include <iostream>
using namespace std;
int main() {
	int N, M; string S;
	cin >> N >> M >> S;
	vector<vector<int> > G(N);
	vector<int> ca(N), cb(N);
	for (int i = 0; i < M; ++i) {
		int a, b;
		cin >> a >> b; --a, --b;
		G[a].push_back(b);
		G[b].push_back(a);
		if (S[a] == 'A') ++ca[b]; else ++cb[b];
		if (S[b] == 'A') ++ca[a]; else ++cb[a];
	}
	queue<int> que;
	for (int i = 0; i < N; ++i) {
		if (ca[i] == 0 || cb[i] == 0) {
			que.push(i);
		}
	}
	int cnt = 0;
	while (!que.empty()) {
		int u = que.front(); que.pop();
		++cnt;
		for (int i : G[u]) {
			bool notyet = (ca[i] != 0 && cb[i] != 0);
			if (S[u] == 'A') --ca[i]; else --cb[i];
			if (notyet && (ca[i] == 0 || cb[i] == 0)) {
				que.push(i);
			}
		}
	}
	cout << (cnt != N ? "Yes" : "No") << endl;
	return 0;
}