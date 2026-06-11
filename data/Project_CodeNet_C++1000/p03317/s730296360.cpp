#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int g = 1;
	while (true) {
		int  tmp = k + (g - 1) * (k - 1);
		if (tmp < n) {

		}
		else {
			break;
		}
		g++;
	}
	cout << g << endl;
	return 0;
}