#include<iostream>
#include<math.h>
#include<string>
#include<algorithm>
using namespace std;

double a[114514];

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++)cin >> a[i];
	sort(a, a + n);
	int ans1, ans2;
	ans1 = a[n - 1];
	double key = a[n - 1] / 2;
	double d = 1100000000;
	for (int i = 0; i < n - 1; i++) {
		if (fabs(a[i] - key) < d) {
			d = fabs(a[i] - key);
			ans2 = a[i];
		}
	}
	cout << ans1 << " " << ans2 << endl;
	return 0;
}
