#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int>A(N);
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
		ans += A[i] - 1;
	}
	cout << ans << endl;
}
