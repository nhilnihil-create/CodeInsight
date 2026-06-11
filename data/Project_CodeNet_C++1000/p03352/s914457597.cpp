#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int x; cin >> x;
	int ans = 0;
	for (int y = x; y  >= 1; y--) {
		for (int b = 1; b <= 100; b++) {
			for (int p = 2; p <= 5; p++) {
				if (y == pow(b, p)) {
					ans = max(ans, y);
				}
			}			
		}
	}
	cout << ans << endl;
	return 0;
	
}