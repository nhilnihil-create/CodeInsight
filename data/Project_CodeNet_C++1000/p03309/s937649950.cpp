#include <bits/stdc++.h>
using namespace std;

int main() {

	int n; cin >> n;
	
	vector<long long> a(n); for (int i = 0; i < n; i++) {
		long long tmp_a;
		cin >> tmp_a;
		a[i] = tmp_a - (i + 1);
	}

	sort(a.begin(), a.end());

	long long tmp_b;
	if (n % 2 == 0) tmp_b = (a[n / 2 - 1] + a[n / 2]) / 2;
	else tmp_b = a[(n - 1) / 2];

	long long ans = 0;
	for (int i = 0; i < n; i++) ans += abs(a[i] - tmp_b);
	
	cout << ans << endl;
	return 0;
}