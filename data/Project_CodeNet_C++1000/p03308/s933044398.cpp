#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <map>

using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) cin >> A[i];
	int ans = 0;
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			int diff = abs(A[i] - A[j]);
			ans = max(ans, diff);
		}
	}
	cout << ans << endl;
	return 0;
}