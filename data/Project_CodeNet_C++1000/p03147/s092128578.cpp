#include "bits/stdc++.h"
using namespace std;
int main() {
	long long N;
	cin >> N;
	vector<long long>H(N);
	long long MAX = -1;
	for (long long i = 0; i < N; i++) {
		cin >> H.at(i);
	}
	long long ans = 0;
	for (long long i = 0; i < 200; i++) {
		long long num = 0;
		bool check = false;
		for (long long j = 0; j < N; j++) {
			if (H.at(j) > 0) check = true;
		}
		if (!check) {
			cout << ans << endl;
			return 0;
		}
		if (H.at(0) > 0) {
			num++;
		}
		for (long long j = 1; j < N; j++) {
			if (H.at(j - 1) <= 0 && H.at(j) > 0) {
				num++;
			}
			H.at(j - 1)--;
		}
		H.at(N - 1)--;
		ans += num;
	}
}