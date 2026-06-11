#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	double a[n];
	for (int i = 0; i < n; ++i) cin >> a[i];


	double sum = 0;
	for (int i = 0; i < n; ++i) sum += (double)a[i];
	sum /= n;

	double sa = 100000000;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (abs(a[i] - sum) < sa) {
			sa = abs(a[i] - sum);
			ans = i;
		}
		
	}
	cout << ans << endl;

	return 0;
}