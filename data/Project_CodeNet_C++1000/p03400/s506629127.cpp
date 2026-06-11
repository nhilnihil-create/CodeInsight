#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, d, x;
	cin >> n >> d >> x;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int total = x;
	for (int i = 0; i < n; ++i) {
		int temp = (d - 1) / a[i] + 1;
		total += temp;
	}
	cout << total << '\n';
	
	return 0;
}
