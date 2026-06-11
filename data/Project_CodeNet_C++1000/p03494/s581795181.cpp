#include "bits/stdc++.h"

using namespace std;

int main() {
	int N;
	cin >> N;
	int ans = 1e9;
	for (int i = 0; i < N; ++i) {
		int n;
		cin >> n;
		int count = 0;
		while (0 == n % 2) {
			count++;
			n /= 2;
		}
		ans = min(ans, count);
	}
	cout << ans << endl;
	return 0;
}
