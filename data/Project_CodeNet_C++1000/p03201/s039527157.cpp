#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#pragma warning (disable: 4996)
using namespace std;

long long N, A[1 << 18];
map<long long, int> Map;
vector<long long> B;
long long M, X[1 << 18], Y[1 << 18];

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i]; Map[A[i]]++;
		B.push_back(A[i]);
	}
	sort(B.begin(), B.end());
	B.erase(unique(B.begin(), B.end()), B.end());

	M = B.size();
	for (int i = 0; i < B.size(); i++) {
		X[i + 1] = B[i];
		Y[i + 1] = Map[B[i]];
	}

	long long ans = 0;
	for (int i = M; i >= 1; i--) {
		long long val = 0;
		for (int j = 0; j <= 60; j++) {
			if ((1LL << j) > X[i]) { val = (1LL << j) - X[i]; break; }
		}
		if (val == X[i]) {
			ans += (Y[i] / 2);
			Y[i] %= 2;
		}
		else {
			int pos1 = lower_bound(X + 1, X + M + 1, val) - X;
			if (X[pos1] == val) {
				long long ret = min(Y[pos1], Y[i]);
				Y[pos1] -= ret;
				Y[i] -= ret;
				ans += ret;
			}
		}
	}
	cout << ans << endl;
	return 0;
}