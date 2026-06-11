#include "bits/stdc++.h"
using namespace std;

int main() {
	long long N, K;
	cin >> N >> K;
	long long ans = 0;
	if (0 == K%2) {
		ans = (N / K)*(N / K)*(N / K);
		ans += ((N + K / 2) / K)*((N + K / 2) / K)*((N + K / 2) / K);
	}
	else {
		ans = (N / K)*(N / K)*(N / K);
		
	}
	cout << ans <<  endl;
	return 0;
}