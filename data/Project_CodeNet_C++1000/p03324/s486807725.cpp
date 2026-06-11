#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int d, n; cin >> d >> n;
	int ans;
	if (d == 0) {
		if (n < 100) ans = n;
		else ans = 101;
	}
	else if (d == 1) {
		if (n < 100) ans = n * 100;
		else ans = 101 * 100;
	}	
	else {
		if (n < 100) ans = n * 100 * 100;
		else ans = 101 * 100 * 100;
	}
	cout << ans << endl;
	return 0;
}