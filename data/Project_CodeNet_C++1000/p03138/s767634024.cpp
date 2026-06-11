#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long N, K, A[1 << 18];

long long solve(long long r) {
	long long cnt = 0;
	for (int i = 1; i <= N; i++) cnt += (r ^ A[i]);
	return cnt;
}

int main() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++) cin >> A[i];

	long long val = 0;
	for (int i = 40; i >= 0; i--) {
		long long nex = val + (1LL << i);
		long long ch1 = solve(val);
		long long ch2 = solve(nex);
		if (nex <= K && ch1 < ch2) { val = nex; }
	}
	cout << solve(val) << endl;
	return 0;
}