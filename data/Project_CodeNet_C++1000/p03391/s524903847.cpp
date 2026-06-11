#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int> A(N), B(N);
	for (int i = 0; i < N; ++i) cin >> A[i] >> B[i];
	if (A == B) cout << 0 << endl;
	else {
		long long sum = 0;
		int mn = (1 << 30);
		for (int i = 0; i < N; ++i) {
			sum += B[i];
			if (A[i] > B[i]) mn = min(mn, B[i]);
		}
		cout << sum - mn << endl;
	}
	return 0;
}