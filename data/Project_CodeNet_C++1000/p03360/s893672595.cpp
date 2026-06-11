#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	const int p = 3;
	vector<int> c(p);
	for (int i = 0; i < p; i++) {
		cin >> c[i];
	}
	int k; cin >> k;
	sort(c.rbegin(), c.rend());
	while (k--) {
		c[0] *= 2;
	}
	cout << c[0] + c[1] + c[2] << endl;
	return 0;
}