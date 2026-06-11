#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	double ave = 0;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a.at(i) = x;
		ave += x;
	}
	ave /= n;
	int ans = n;
	double rec = 1000;
	for (int i = 0; i < n; i++) {
		double gap = a.at(i) - ave;
		gap = abs(gap);
		if (gap < rec) {
			rec = gap;
			ans = i;
		}
	}
	cout << ans << endl;
}