// abc125_a.cc
#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a, b, t;
	cin >> a >> b >> t;

	int ans = 0;
	for (int i = a; i <= t; i += a) {
		ans += b;
	}

	cout << ans << "\n";
}