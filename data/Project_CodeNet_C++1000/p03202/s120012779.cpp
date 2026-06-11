#include "bits/stdc++.h"
using namespace std;

static long long N, A[200000];
map<long long, long long> mp;

bool check(long long X) {
	mp.clear();
	for (int i = 1; i < N; i++) {
		if (A[i - 1] >= A[i]) {
			auto it = mp.upper_bound(A[i]);
			mp.erase(it, mp.end());
			mp[A[i]]++;
			long long NOW = A[i];
			while (mp[NOW] == X) {
				mp.erase(NOW);
				NOW--;
				if (NOW == 0) return false;
				mp[NOW]++;
			}
		}
	}
	return true;
}

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	bool check1 = true;
	for (int i = 0; i < N - 1; i++) {
		if (A[i + 1] <= A[i]) check1 = false;
	}
	if (check1) {
		cout << 1 << endl;
		return 0;
	}
	long long L = 1, R = N + 1;
	while (R - L > 1) {
		long long MID = (L + R) / 2;
		check(MID) ? R = MID : L = MID;
	}
	cout << R << endl;
}