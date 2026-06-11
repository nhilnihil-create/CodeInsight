#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<double> x(n);
	vector<string> u(n);
	for (int i = 0; i < n; i++) {
		cin >> x[i] >> u[i];
	}
	double sum = 0.0;
	for (int i = 0; i < n; i++) {
		if (u[i].compare("JPY") == 0) {
			sum += x[i];
		}
		if (u[i].compare("BTC") == 0) {
			sum += (380000.0 * x[i]);
		}
	}
	cout << sum << '\n';
	
	return 0;
}
