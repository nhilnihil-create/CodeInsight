#include <cfloat>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, ans;
	cin >> N;
	vector<double> a(N);
	double b = 0.0, c = DBL_MAX;
	for (double& i : a) {
		cin >> i;
		b += i;
	}
	for (int i = 0; i < N; ++i) {
		if (c > fabs(a[i] - b / N)) {
			ans = i;
			c = fabs(a[i] - b / N);
		}
	}
	cout << ans;
}