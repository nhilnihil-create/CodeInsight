#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <string>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> a(n + 2, 0);
	long long total = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		total += abs(a[i] - a[i-1]);
	}
	total += abs(a[n]);

	for (int i = 1; i <= n; i++) {
		int x = abs(a[i-1] - a[i]) + abs(a[i] - a[i+1]);
		int y = abs(a[i-1] - a[i+1]);

		cout << total - x + y << endl;
	}

	return 0;
}
