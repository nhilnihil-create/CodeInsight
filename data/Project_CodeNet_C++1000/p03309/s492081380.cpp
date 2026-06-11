#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] -= i;
	}
	sort(a.begin(), a.end());
	int b = a[n/2];
	long long ans = 0;
	for (int i = 0; i < n; i++) {
		ans += abs(a[i] - b);
	}
	cout << ans << endl;
	return 0;
}