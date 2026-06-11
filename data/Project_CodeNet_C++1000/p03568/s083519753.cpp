#include "bits/stdc++.h"
using namespace std;
typedef pair<double, double> P;
int main() {
	long long N;
	cin >> N;
	vector<long long>A(N);
	for (long long i = 0; i < N; i++) {
		cin >> A.at(i);
	}
	long long ans = 0;
	for (long long i = 1; i < (1 << N); i++) {
		long long num = 1;
		queue<long long>Even;
		for (long long j = 0; j < N; j++) {
			if (i & (1 << j)) Even.push(j);
		}
		for (long long j = 0; j < N; j++) {
			if (!Even.empty()) {
				if (j == Even.front()) {
					if (A.at(j) % 2 != 0) num *= 2;
					else num *= 1;
					Even.pop();
				}
				else {
					if (A.at(j) % 2 != 0) num *= 1;
					else num *= 2;
				}
			}
			else {
				if (A.at(j) % 2 != 0) num *= 1;
				else num *= 2;
			}
		}
		ans += num;
	}
	cout << ans << endl;
}