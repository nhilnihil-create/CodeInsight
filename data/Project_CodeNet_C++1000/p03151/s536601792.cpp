#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	vector<int>A(N), B(N);
	long long Asum = 0, Bsum = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		Asum += A[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> B[i];
		Bsum += B[i];
	}
	if (Bsum > Asum) {
		cout << -1 << endl;
		return 0;
	}
	vector<int> C;
	int ans = 0;
	long long difsum = 0;
	for (int i = 0; i < N; i++) {
		if (A[i] >= B[i]) C.push_back(A[i] - B[i]);
		else {
			ans++;
			difsum += B[i] - A[i];
		}
	}
	sort(C.begin(), C.end(), greater<int>());
	int i = 0;
	while (difsum > 0) {
		difsum -= C[i];
		i++;
		ans++;
	}
	cout << ans << endl;
}
