#include "bits/stdc++.h"

using namespace std;
int main() {
	int N,M;
	cin >> N >> M;
	vector<int>S(M);
	for (int n = 0; n < M; ++n) {
		int num;
		cin >> num;
		for (int m = 0;m<num;++m) {
			int num2;
			cin >> num2;
			S[n] |= 1 << (num2-1); 
		}
	}
	vector<int>P(M);	
	for (int n = 0; n < M; ++n) {
		cin >> P[n];
	}
	int roop = 1 << (N);
	int ans = 0;
	for (int n = 0;n<roop;++n) {
		int num = 0;
		for (int m = 0;m < M;++m) {
			int count = 0;
			for (int l = 0;l<N;++l) {
				if (S[m]&1<<(l)) {
					if (n & 1<<l) {
						++count;
					}
				}
			}
			if (P[m] == count %2) {
				++num;
			}
		}
		if (M == num) {
			++ans;
		}
	}
	cout << ans << endl;
}
