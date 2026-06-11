#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

void show(vector<int> &v) {
	for (auto x: v) {
		printf("%3d ", x);
	}
	printf("\n");
}

void check(vector<int> a, vector<int> x, vector<int> y) {
	printf("check\n");
	printf("    ");
	show(a);

	for (int i = 0; i < x.size(); i++) {
		printf("%2d: ", i);
		a[y[i]] += a[x[i]];
		show(a);
	}
}

int main() {
	int n;
	cin >> n;

	vector<int> a(n, 0), x, y;
	int i1 = 0; // 最小
	int i2 = 0; // 最大
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < a[i1]) { i1 = i;}
		if (a[i] > a[i2]) { i2 = i;}
	}

	if (abs(a[i2]) > abs(a[i1])) {
		for (int i = 0; i < n; i++) {
			if (i != i2) {
				x.emplace_back(i2);
				y.emplace_back(i);
			}
		}
		for (int i = 1; i < n; i++) {
				x.emplace_back(i-1);
				y.emplace_back(i);
		}
	} else {
		for (int i = 0; i < n; i++) {
			if (i != i1) {
				x.emplace_back(i1);
				y.emplace_back(i);
			}
		}
		for (int i = n - 1; i > 0; i--) {
				x.emplace_back(i);
				y.emplace_back(i-1);
		}
	}

	cout << x.size() << endl;
	for (int i = 0; i < x.size(); i++) {
		cout << x[i] + 1 << " " << y[i] + 1 << endl;
	}

	// check(a, x, y);
	return 0;
}
