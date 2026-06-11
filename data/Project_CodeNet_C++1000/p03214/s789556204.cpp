#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	double ave = 0;
	vector<int> a;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		ave += x;
		a.push_back(x);
	}
	ave /= n;

	double minimum = 99999999.0;
	int count = -1;
	for (int i = 0; i < n; i++) {
		if (minimum > abs(a[i] - ave)) count = i;
		minimum = min(minimum, abs(a[i] - ave));
	}

	cout << count << endl;

	return 0;
}