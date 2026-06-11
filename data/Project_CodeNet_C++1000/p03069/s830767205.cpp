#include "bits/stdc++.h"
using namespace std;


int main()
{
	int n;
	string s;
	cin >> n >> s;

	vector<int> kuro_sum(n, 0);		// その番号までの黒石の合計
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			if (s[i] == '#') {
				kuro_sum.at(i) = 1;
			} else {
				kuro_sum.at(i) = 0;
			}
		} else {
			if (s[i] == '#') {
				kuro_sum.at(i) = kuro_sum.at(i - 1) + 1;
			} else {
				kuro_sum.at(i) = kuro_sum.at(i - 1);
			}
		}
	}

	vector<int> ans(n + 1, n);
	// 全部黒
	ans.at(0) = n - kuro_sum.at(n - 1);

	// i個めから全部黒(1 <= i <= n - 1)
	for (int i = 1; i < n; i++) {
		ans.at(i) = kuro_sum.at(i - 1) + ((n - i) - (kuro_sum.at(n - 1) - kuro_sum.at(i - 1)));
	}

	// 全部白
	ans.at(n) = kuro_sum.at(n - 1);

	sort(ans.begin(), ans.end());
	cout << ans.at(0) << endl;
}