#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int a, b, k; cin >> a >> b >> k;
	vector<int> c;
	for (int i = 1; i <= max(a,b); i++) {
		if (a % i == 0 && b % i == 0) {
			c.push_back(i);
		}
	}
	sort(c.rbegin(), c.rend());
	cout << c[k - 1] << endl;
	return 0;
}