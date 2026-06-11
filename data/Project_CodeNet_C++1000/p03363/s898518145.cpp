#include <bits/stdc++.h>
using namespace std;

int main() {
	// cin.tie(0);
	// ios::sync_with_stdio(false);

	map<long long, long long> sum_map;

	int N;
	scanf("%d", &N);

	long long a, sum = 0;
	sum_map[0]++;
	for (int i = 0; i < N; i++) {
		scanf("%lld", &a);
		sum += a;
		sum_map[sum]++;
	}

	long long result = 0;
	for (auto i : sum_map) {
		// cout << i.first << ":" << i.second << "\n";
		result += i.second * (i.second - 1) / 2;
	}
	cout << result;
	return 0;
}