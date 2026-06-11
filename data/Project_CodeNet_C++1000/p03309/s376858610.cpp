#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int inf = 1012345678;
int main() {
	int N;
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		A[i] -= i;
	}
	sort(A.begin(), A.end());
	int mid = A[N / 2];
	long long ans = 0;
	for (int i = 0; i < N; ++i) {
		ans += abs(A[i] - mid);
	}
	cout << ans << endl;
	return 0;
}