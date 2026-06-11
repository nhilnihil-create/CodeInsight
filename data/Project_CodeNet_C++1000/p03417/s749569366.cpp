#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

int main() {
	long long n, m;
	cin >> n >> m;

	if (n > m) {
		swap(n, m);
	}

	if (n == 1) {
		if (m == 1) {
			cout << 1 << endl;
		} else if (m == 2) {
			cout << 0 << endl;
		} else {
			cout << m - 2 << endl;
		}
	} else {
		cout << (n - 2) * (m - 2) << endl;
	}
	return 0;
}
