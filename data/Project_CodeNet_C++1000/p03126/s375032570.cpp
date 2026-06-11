#include "bits/stdc++.h"
using namespace std;

int main() {
	int N,M;
	cin >> N>>M;
	vector<int>X(M);
	for (int n = 0; n < N; ++n) {
		int K;
		cin >> K;
		for (int m = 0;m<K;++m) {
			int num;
			cin >> num;
			num--;
			X[num]++;
		}
	}
	int ans = 0;
	for (int m = 0;m<M;++m) {
		if (N == X[m]) {
			ans++;
		}
	}
	cout << ans << endl;
}