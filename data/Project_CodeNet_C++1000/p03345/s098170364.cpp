#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main() {
	long long a, b, c, k;
	cin >> a >> b >> c >> k;

	if (abs(a - b) > 10e18) cout << "Unfair" << endl;
	else if (k % 2 == 0) cout << a - b << endl;
	else cout << -a + b << endl;

	return 0;
}