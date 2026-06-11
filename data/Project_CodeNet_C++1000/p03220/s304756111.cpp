#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <iomanip>


using namespace std;



int main() {

	int N, T, A, H0, ans;
	double dif, min = 100000;

	cin >> N >> T >> A;

	for (int i = 0; i < N; i++) {
		cin >> H0;
		dif = abs(A - (T - H0 * 0.006));
		if (dif < min) {
			min = dif;
			ans = i + 1;
		}
	}

	cout << ans;

	return 0;

}