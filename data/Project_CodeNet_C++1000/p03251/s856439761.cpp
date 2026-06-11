#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, m, x_c, y_c;
	cin >> n >> m >> x_c >> y_c;

	int x[n];
	int y[m];
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int  i = 0; i < m; i++) {
		cin >> y[i];
	}

	string ans = "War";
	if (x_c < y_c) {
		sort(x, x+n);
		sort(y, y+m);
		if (x[n-1] < y[0] && x[n-1] < y_c && x_c < y[0]) {
			ans = "No War";
		}
	}
	cout << ans << endl;
	return 0;
}
