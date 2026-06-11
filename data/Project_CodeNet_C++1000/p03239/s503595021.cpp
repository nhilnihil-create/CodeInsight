#include <iostream>
using namespace std;

int main() {
	int n, t_l;
	cin >> n >> t_l;
	int c[n], t[n];
	for (int i = 0; i < n; i++) {
		cin >> c[i] >> t[i];
	}

	int ans = 1e8;
	for (int i = 0; i < n; i++) {
		if(t[i] <= t_l && c[i] < ans) {
			ans = c[i];
		}
	}
	if (ans == 1e8) {
		cout << "TLE" << endl;
	} else {
		cout << ans << endl;
	}
	return 0;
}
