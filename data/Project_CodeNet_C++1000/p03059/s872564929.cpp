#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	double a, b, T; cin >> a >> b >> T;
	int ans = 0;
	double t = 0;
	while (true) {
		t += a;
		if (t >= T + 0.5) {
			break;
		}
		ans += b;
	}
	cout << ans << endl;
	return 0;
}