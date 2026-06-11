#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <utility>

using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	vector<int> w(n);
	vector<int> e(n);
	for (int i = 0; i < n; i++) {
		if (s.at(i) == 'W') {
			w.at(i)++;
		}
		else {
			e.at(i)++;
		}
		if (i != 0) {
			w.at(i) += w.at(i - 1);
			e.at(i) += e.at(i - 1);
		}
	}
	
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		if (i != 0) ans.at(i) += w.at(i - 1);
		ans.at(i) += e.at(n - 1) - e.at(i);
	}

	sort(ans.begin(), ans.end());
	cout << ans.at(0) << endl;

	return 0;
}