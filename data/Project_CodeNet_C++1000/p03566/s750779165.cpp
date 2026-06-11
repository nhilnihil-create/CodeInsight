#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> t(n), v(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	b[n-1] = 0;
	for (int i = n-1; i > 0; i--) {
		b[i-1] = min({b[i] + t[i], v[i], v[i-1]});
	}

	int a = 0;
	double ans = 0;
	for (int i = 0; i < n; i++) {
		if (a+t[i] < b[i]) b[i] = min(b[i], a+t[i]);
		double x = double(b[i]+t[i]-a) / 2;
		ans += a*x + x*x/2 + b[i]*(t[i]-x) + (t[i]-x)*(t[i]-x)/2;
		if (a + x > v[i]) {
			double tmp = double(a+b[i]+t[i]) / 2 - v[i];
			ans -= tmp * tmp;
		}
		a = b[i];
	}
	cout << fixed << setprecision(15);
	cout << ans << endl;
	return 0;
}