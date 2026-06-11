#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	double t, x;
	cin >> t >> x;
	vector<double> v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	double ans = 1e9;
	int index = 0;
	for (int i = 0; i < n; ++i) {
		double p = abs(x - t  + v[i] * 0.006);
		//cout << p << endl;
		if (p < ans) {
			index = i;
			ans = p;
		}
	}
	cout << index + 1;
}
