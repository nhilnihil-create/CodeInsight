#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<double> a(n);
	double ave = 0.0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ave += a[i];
	}
	ave /= n;

	double mn = 1010101010;
	int ans = -1;
	for (int i = 0; i < n; i++) {
		a[i] = fabs(ave - a[i]);

		if (a[i] < mn) {
			mn = a[i];
			ans = i;
		}
	}
	cout << ans << endl;

	return 0;
}