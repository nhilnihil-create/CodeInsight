#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int k; cin >> k;
	int ans;
	if (k % 2 == 0) {
		ans = (k / 2) * (k / 2);
	}
	else {
		ans = (k + 1) / 2 * (k / 2);
	}
	cout << ans << endl;
	return 0;
}