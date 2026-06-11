#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n, m; cin >> n >> m;
	int cnt = m;
	ll tmp = 1;
	while (cnt--) {
		tmp *= 2;
	}
	cout << (1900 * m + (n - m) * 100) * tmp << endl;
	return 0;
}