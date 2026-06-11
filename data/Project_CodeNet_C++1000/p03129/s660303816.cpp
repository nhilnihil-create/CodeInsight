#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	if (n % 2 == 0) {
		if (k <= n / 2) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	} else {
		if (k <= n / 2 + 1) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}

	return 0;
}

