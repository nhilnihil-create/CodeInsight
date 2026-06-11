#include <bits/stdc++.h>
using namespace std;

#define MAX 100000

int main() {
	int N, K;
	int x[MAX];
	int ans = INT_MAX;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < N - K + 1; i++) {
		int d = min(abs(x[i + K - 1]) + x[i + K - 1] - x[i],
					abs(x[i]) + x[i + K - 1] - x[i]);
		ans = min(ans, d);
	}
	cout << ans << endl;
	return 0;
}
