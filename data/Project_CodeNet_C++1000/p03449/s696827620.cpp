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
	vector<vector<int>> a(2, vector<int>(n));
	for (int i = 0; i < n; i++) {
		cin >> a.at(0).at(i);
	}
	for (int i = 0; i < n; i++) {
		cin >> a.at(1).at(i);
	}

	int ans = 0;

	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j <= i; j++) {
			sum += a.at(0).at(j);
		}
		for (int k = i; k < n; k++) {
			sum += a.at(1).at(k);
		}
		ans = max(ans, sum);
	}

	cout << ans << endl;

	return 0;
}