#include <bits/stdc++.h>
using namespace std;

int main() {
	int i;
	set<int> a;
	cin >> i;
	for (int m = 2;; m++) {
		a.insert(i);
		i = (i % 2 == 0) ? (i / 2) : (3 * i + 1);
		if (a.find(i) != a.end()) {
			cout << m << endl;
			break;
		}
	}
	return 0;
}
