#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> ans;
	int sum = n * (n + 1) / 2;
	int sum_t = sum - n;
	for (int i = 1; i < n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (n % 2 == 0) {
				if (n + 1 - i != j) {
					ans.emplace_back(make_pair(i, j));
				}
			} else {
				if (j != n - i) {
					ans.emplace_back(make_pair(i, j));
				}
			}
		}
	}

	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}

	return 0;
}