#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> A(N), B(N);
	for (int i = 0; i < N; ++i) cin >> A[i];
	for (int i = 0; i < N; ++i) cin >> B[i];
	int ans = 0;
	for (int i = 0; i < 29; ++i) {
		vector<int> bs(2 * N);
		for (int j = 0; j < N; ++j) {
			bs[j] = B[j] % (2 << i);
			bs[j + N] = bs[j] + (2 << i);
		}
		sort(bs.begin(), bs.end());
		long long sum = 0;
		for (int j = 0; j < N; ++j) {
			int pl = lower_bound(bs.begin(), bs.end(), (2 << i) - (A[j] % (2 << i)) + (1 << i)) - bs.begin();
			int pr = lower_bound(bs.begin(), bs.end(), (2 << i) - (A[j] % (2 << i)) + (2 << i)) - bs.begin();
			sum += pr - pl;
		}
		if (sum % 2 == 1) {
			ans += 1 << i;
		}
	}
	cout << ans << endl;
	return 0;
}