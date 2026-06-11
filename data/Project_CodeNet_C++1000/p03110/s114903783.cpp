#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	double x[n];
	string u[n];
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> u[i];
	}

	double ans = 0;
	for (int i = 0; i < n; i++) {
		if (u[i] == "JPY") {
			ans += x[i];
		} else {
			ans += 38e4 * x[i];
		}
	}
	cout << ans << endl;
	return 0;
}