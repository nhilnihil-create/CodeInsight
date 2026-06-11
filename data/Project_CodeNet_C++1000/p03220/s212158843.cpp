#include<iostream>
#include<cmath>
using namespace std;

int main() {

	int n;

	int t, a;
	int ans = -1;
	double min = 10000000;
	cin >> n;
	cin >> t >> a;

	for (int i = 0; i < n; i++) {
		double h;

		cin >> h;
		double kion = t - h * 0.006;
		if (abs(a - kion) < min) {
			ans = i+1;
			min = abs(a - kion);
		}

	


	}
	cout << ans << endl;
	return 0;
}