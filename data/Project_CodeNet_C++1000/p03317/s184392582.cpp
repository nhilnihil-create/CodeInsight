#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <string>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> a(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	int ans = 0;
	n -= k;
	ans++;

	if (n > 0) {
		k--;
		ans += (n + k - 1) / k;
	}
	cout << ans << endl;
	return 0;
}
