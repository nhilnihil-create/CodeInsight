#include "bits/stdc++.h"
using namespace std;

int main() {
	int D, N;
	cin >> D >> N;
	int count = 1;
	int ans = pow(100, D);
	int memo = 1;
	while (count != N) {
		memo++;
		if (0 != (memo % 100)) {
			count++;
		}
	}
	ans *= memo;
	cout << ans << endl;
	return 0;
}