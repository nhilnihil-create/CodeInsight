#include <bits/stdc++.h>
#define Int int64_t

using namespace std;

int main() {
	int N;
	cin >> N;

	// 3 : 2, 3, 25
	// n : 2, 4, 3, 9

	if (N == 3) {
		cout << "2 3 25" << endl;
		return 0;
	}

	vector<int> ans = { 2, 4, 3, 9 };
	for (int i = 15; i <= 30000; i += 12) {
		if (ans.size() >= N - 1) { break; }
		ans.emplace_back(i);
		ans.emplace_back(i + 6);
	}
	for (int i = 8; i + 2 <= 30000; i += 6) {
		if (ans.size() >= N - 1) { break; }
		ans.emplace_back(i);
		ans.emplace_back(i + 2);
	}
	for (int i = 6; i <= 30000; i += 6) {
		if (ans.size() >= N) { break; }
		ans.emplace_back(i);
	}

	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << (i < ans.size() - 1 ? " " : "\n");
	}

	return 0;
}
