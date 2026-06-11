#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<vector<int> > G(N);
	for (int i = 0; i < N - 1; ++i) {
		int a, b;
		cin >> a >> b; --a, --b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<int> C(N);
	for (int i = 0; i < N; ++i) {
		cin >> C[i];
	}
	sort(C.begin(), C.end());
	int cnt = 0;
	vector<int> D(N);
	function<void(int, int)> dfs = [&](int pos, int pre) {
		for (int i : G[pos]) {
			if (i == pre) continue;
			dfs(i, pos);
		}
		D[pos] = C[cnt++];
	};
	dfs(0, -1);
	int sum = 0;
	for (int i = 0; i < N - 1; ++i) {
		sum += C[i];
	}
	cout << sum << endl;
	for (int i = 0; i < N; ++i) {
		if (i) cout << ' ';
		cout << D[i];
	}
	cout << endl;
	return 0;
}