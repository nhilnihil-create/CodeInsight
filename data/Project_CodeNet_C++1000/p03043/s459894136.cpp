#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	double ans = 0;
	for (int i = 1; i <= N; i++) {
		double temp = 1.0 / N;
		int now = i;
		while (now < K) {
			now *= 2;
			temp /= 2;
		}
		ans += temp;
	}
	cout << fixed << setprecision(9) << ans << endl;

	return 0;
}