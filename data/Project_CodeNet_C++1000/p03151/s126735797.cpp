#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, A[1 << 18], B[1 << 18], C[1 << 18], sum, cnt; vector<long long>X;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) {
		cin >> B[i];
		if (A[i] >= B[i]) X.push_back(A[i] - B[i]);
		else { sum += (B[i] - A[i]); cnt++; }
	}
	sort(X.begin(), X.end()); reverse(X.begin(), X.end());
	for (int i = 0; i < X.size(); i++) {
		if (sum > 0) { sum -= X[i]; cnt++; }
	}
	if (sum > 0) cnt = -1;
	cout << cnt << endl;
	return 0;
}