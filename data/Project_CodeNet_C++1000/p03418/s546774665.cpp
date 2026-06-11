#include "bits/stdc++.h"
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	long long ans = 0;
	for (int i = K + 1; i <= N; ++i) {
		ans += (i - K)*((1 + N) / i);
		ans += max(0, ((N + 1)%i) - K); 
		if (0 == K) {
			ans--;
		}
	}
	cout << ans << endl;
}
