#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll k, a, b;
	cin >> k >> a >> b;
	if (k == 1) cout << 2 << endl;
	else if (k <= a) cout << k+1 << endl;
	else {
		if (a + 3 <= b) {
			k -= a - 1;
			if (k % 2 == 0)cout << a + (k / 2) * (b - a) << endl;
			else cout << a + (k / 2) * (b - a) + 1 << endl;
		}
		else cout << k+1 << endl;
	}
}