#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++) cin >> vec.at(i);
	//vecの中のj番目=j(配列内最大)を取り除いていくゲーム
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		int max_match = 0;
		for (int j = 0; j < vec.size(); j++) {
			if (j + 1 == vec.at(j)) {
				if (max_match < vec.at(j)) max_match = vec.at(j);
			}
		}
		if (max_match == 0) {
			cout << -1 << endl;
			ans.clear();
			break;
		}
		else {
			ans.at(i) = max_match;
		}
		vec.erase(vec.begin() + max_match - 1);
	}
	reverse(ans.begin(), ans.end());
	if (ans.size() == n) {
		cout << ans.at(0);
		for (int i = 1; i < n; i++) cout << endl << ans.at(i);
	}
}