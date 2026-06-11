#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	int N;
	cin >> N;

	vector<pair<int, int>> ans;
	int n = N + (1 - N % 2);
	for (int i = 1; i < N; ++i) {
		for (int j = i + 1; j <= N; ++j) {
			if (j == i || i + j == n) { continue; }
			ans.emplace_back(i, j);
		}
	}

	cout << ans.size() << endl;
	for (auto p : ans) {
		cout << p.first << " " << p.second << endl;
	}

	return 0;
}
