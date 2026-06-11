#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] -= i;
	}
	sort(a.begin() + 1, a.end());
	int b;
	if (n % 2 == 0)
		b = (a[n / 2] + a[n / 2 + 1]) / 2;
	else
		b = a[n / 2 + 1];
	long long ans = 0;
	for (int i = 1; i <= n; i++)
		ans += abs(a[i] - b);
	cout << ans << endl;
	return 0;
}
