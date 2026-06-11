#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a, b, c, x;
	cin >> a >> b >> c >> x;
	int res = 0;
	for (int i = 0; i <= a; i++) {
		for (int j = 0; j <= b; j++) {
			for (int k = 0; k <= c; k++) {
				int total = 500 * i + 100 * j + 50 * k;
				if (total == x) {
					res++;
				}
			}
		}
	}
	cout << res << '\n';	
	
	return 0;
}
