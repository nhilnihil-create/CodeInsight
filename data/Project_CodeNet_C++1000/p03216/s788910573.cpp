#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long N, Q, K[100];
long long c1[1 << 20], c2[1 << 20], c3[1 << 20];
string S;

long long solve(long long border) {
	long long ans = 0; border--;
	long long tops = 0, kosuu = 0;
	for (int i = 0; i < N; i++) {
		if (S[i] == 'D') {
			kosuu += 1;
		}
		if (S[i] == 'M') {
			tops += kosuu;
		}
		if (S[i] == 'C') {
			ans += tops;
		}
		if (i >= border && S[i - border] == 'D') {
			long long val = c2[i + 1] - c2[i - border + 1];
			tops -= val;
			kosuu -= 1;
		}
	}
	return ans;
}

int main() {
	cin >> N >> S;
	for (int i = 1; i <= N; i++) {
		c1[i] = c1[i - 1]; c2[i] = c2[i - 1]; c3[i] = c3[i - 1];
		if (S[i - 1] == 'D') c1[i] += 1;
		if (S[i - 1] == 'M') c2[i] += 1;
		if (S[i - 1] == 'C') c3[i] += 1;
	}
	cin >> Q;
	for (int i = 1; i <= Q; i++) cin >> K[i];
	for (int i = 1; i <= Q; i++) cout << solve(K[i]) << endl;
	return 0;
}