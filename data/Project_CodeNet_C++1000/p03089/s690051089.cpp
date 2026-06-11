#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
	int n; cin >> n;
	list<int> b(n);
	vector<int> ans;
	for (auto& e : b) cin >> e;
	while (!b.empty()) {
		int t = b.size();
		for (auto it = b.rbegin(); it != b.rend(); ++it) {
			if (*it == t) {
				b.erase(--it.base());
				ans.push_back(t);
				break;
			}
			--t;
		}
		if (!t) break;
	}
	if (ans.size() != n) cout << -1 << endl;
	else {
		for (int i = n - 1; i >= 0; --i) cout << ans[i] << endl;
	}

	return 0;
}