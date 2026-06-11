#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	int A[3];
	cin >> A[0] >> A[1] >> A[2];
	int ans = 1000;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				if (i == j || j == k || k == i) continue;
				int sum = 0;
				sum += abs(A[j] - A[i]) + abs(A[k] - A[j]);
				ans = min(ans, sum);
			}
		}
	}
	cout << ans << endl;
	return 0;
}